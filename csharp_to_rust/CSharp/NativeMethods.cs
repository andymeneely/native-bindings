using System.Runtime.InteropServices;

static class NativeMethods
{
    [DllImport("nativelib")]
    public static extern int multiply(int a, int b);

    [DllImport("nativelib")]
    public static extern uint hamming_distance(uint a, uint b);
}
