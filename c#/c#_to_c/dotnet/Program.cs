using System;
using System.Runtime.InteropServices;

namespace dotnet {
	class Program {
		// Import our shared functions here
		[DllImport ("libnative")]
		public static extern IntPtr say_hello();

		[DllImport ("libnative")]
		public static extern int multiply(int x, int y);

		[DllImport ("libnative")]
		public static extern int min(int[] array, int len);

		static void Main(string[] args) {
			var hello_ptr = say_hello();
			var hello = Marshal.PtrToStringAnsi(hello_ptr);

			Console.WriteLine(hello);

			var result = multiply(4, 5);

			Console.WriteLine("4 x 5 = " + result);

			int[] arr = { 5, 2, 9, 5, 99 };
			var minimum = min(arr, arr.Length);

			Console.WriteLine("Min of array is " + minimum);

			Console.WriteLine("Press any key to exit . . .");
			Console.ReadKey();
		}
	}
}
