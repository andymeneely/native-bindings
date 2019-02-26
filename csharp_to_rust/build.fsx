open Fake.SystemHelper
#r "paket:
nuget Fake.IO.FileSystem
nuget Fake.DotNet.Cli
nuget Fake.Core.Target
nuget Fake.Core.CommandLineParsing
//"
#load "./.fake/build.fsx/intellisense.fsx"

open Fake.IO
open Fake.DotNet
open Fake.Core

let buildDir = "./build"
let rustDir = "./nativelib"
let csharpDir = "./CSharp"
let cli = """
usage: build [options]

options:
--nonative	    Don't use native CPU type when building nativelib
-t <target>     Optional. Runs the specified target (BuildAll, BenchCSharp, BenchRust)
"""

let parsedArgs = Docopt(cli).Parse(Context.forceFakeContext().Arguments |> List.toArray)
let native = not (DocoptResult.hasFlag "--nonative" parsedArgs)
let target =
    match DocoptResult.tryGetArgument "-t" parsedArgs with
    | Some arg -> arg
    | None -> "BuildAll"

Target.create "Clean" (fun _ ->
    Shell.cleanDir buildDir
    ignore(Shell.Exec("cargo", "clean", rustDir))
)

Target.create "BuildRust" (fun _ ->
    if native then
        Environment.setEnvironVar "RUSTFLAGS" "-C target-cpu=native" // enalbes use of popcnt instruction in build
    ignore(Shell.Exec("cargo", "build --release", rustDir))
)

Target.create "BuildCSharp" (fun _ ->
    DotNet.build (fun args -> {
            args with Configuration = DotNet.BuildConfiguration.Release
        }) "CSharp/CSharp.csproj"
)

Target.create "BenchCSharp" (fun _ ->
    ignore(Shell.Exec("dotnet", "run -c Release", csharpDir))
)

Target.create "BenchRust" (fun _ ->
    ignore(Shell.Exec("cargo", "bench", rustDir))
)

Target.create "BuildAll" (fun _ ->
    Trace.trace "Test"
)

open Fake.Core.TargetOperators

// means BuildAll depends on BuildCSharp, which depends on BuildNativeLib, which depends on Clean
"Clean"
    ==> "BuildRust"
    ==> "BuildCSharp"
    ==> "BuildAll"

"BuildRust"
    ==> "BenchRust"

"BuildCSharp"
    ==> "BenchCSharp"

Target.runOrDefault target
