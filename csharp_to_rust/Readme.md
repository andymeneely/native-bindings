## Notice
This does NOT work on nitron, since it needs .NET Core, which doesn't run on OpenBSD

**This has only been tested on Windows 10**

## Instructions
1. Install the [.NET Core SDK](https://dotnet.microsoft.com/download)
2. Install the C/C++ portion of the [VS 2017 build tools](https://visualstudio.microsoft.com/downloads/#build-tools-for-visual-studio-2017)
3. Install Rust using [rustup](https://rustup.rs/)
4. Install the FAKE CLI with `dotnet tool install fake-cli -g`
5. cd to the `CSharp` directory and run `dotnet add package System.Runtime.Intrinsics.Experimental --version 4.6.0-preview3-26501-04 --source https://dotnet.myget.org/F/dotnet-core/api/v3/index.json`
    - This is necessary as System.Runtime.Intrinsics isn't stable yet, and is therefore on a separate NuGet feed that isn't registered by default
    - This command will probably break when the library is stabilized
6. cd to the directory with `build.fsx`, and run one of the following commands
    - `fake build`: to just compile both to `build/`
    - `fake build -t BuildCSharp` or `fake build -t BuildRust` to build the C#/Rust portions respectively
    - `fake build -t BenchRust` or `fake build -t BenchCSharp` to run the Rust/C# benchmarks respectively

Benchmark output will be in nativelib/target/criteroin for Rust and CSharp/BenchmarkDotNet.Artifacts for C#