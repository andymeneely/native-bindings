using System;
using System.Collections.Generic;
using System.Runtime.Intrinsics.X86;
using BenchmarkDotNet.Attributes;
using BenchmarkDotNet.Running;

namespace CSharp
{
    class Program
    {
        static void Main(string[] args)
        {
            BenchmarkRunner.Run<Hamming>();
            Console.WriteLine("Grab the artifacts, then press enter");
            Console.ReadLine();
            BenchmarkRunner.Run<Multiply>();
        }
    }

    [ShortRunJob]
    [CsvExporter, CsvMeasurementsExporter, RPlotExporter]
    [DisassemblyDiagnoser(printAsm: true)]
    public class Hamming
    {
        public IEnumerable<(uint, uint)> Numbers() => new (uint, uint)[] {
            (2241772153, 3635078742),
            (224845246, 2076596368),
            (586774217, 2068741568),
            (596452998, 3747699255),
            (907505648, 984890663),
        };

        [ParamsSource(nameof(Numbers))]
        public (uint, uint) Params { get; set; }

        [Benchmark]
        public int CSharpHamming() => Popcnt.PopCount(Params.Item1 ^ Params.Item2);

        [Benchmark]
        public uint RustHamming() => NativeMethods.hamming_distance(Params.Item1, Params.Item2);
    }

    [ShortRunJob]
    [CsvExporter, CsvMeasurementsExporter, RPlotExporter]
    [DisassemblyDiagnoser(printAsm: true)]
    public class Multiply
    {
        public IEnumerable<(int, int)> Numbers() => new (int, int)[] {
            (23278, 25058),
            (24552, 44005),
            (31159, 27339),
            (42587, 19588),
            (44273, 16819)
        };

        [ParamsSource(nameof(Numbers))]
        public (int, int) Params { get; set; }

        [Benchmark]
        public int CSharpMultiply() => Params.Item1 * Params.Item2;

        [Benchmark]
        public int RustMultiply() => NativeMethods.multiply(Params.Item1, Params.Item2);
    }
}
