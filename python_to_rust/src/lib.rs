#[macro_use] extern crate cpython;

use cpython::{Python, PyResult};

/// This will generate a method named PyInit_hello which will be called when
/// Python loads the library. The actual name should be PyInit_<library>
/// where <library> is the library name. For example if your library is named
/// lab3 then you would replace PyInit_hello with PyInit_lab3. The second
/// and third arguments are the same. 
/// 
/// The py_fn! macro takes the Python object, a method, and the arguments to
/// the method, and generates the glue code to allow Python to call the function.
/// 
/// `m.add()` takes a Python object, a method name, and a function, and adds the
/// function to the module. `m.add()` returns a Result and so each line ends with
/// a ? to propogate errors properly. Read the Rust Book for more details.
py_module_initializer!(libhello, PyInit_hello, PyInit_hello, |py, m| {
    m.add(py, "multiply_rs", py_fn!(py, multiply_py(a: i32, b: i32)))?;
    m.add(py, "hamming_rs", py_fn!(py, hamming_py(a: i32, b: i32)))?;
    Ok(())
});

pub fn multiply_py(_: Python, a: i32, b: i32) -> PyResult<i32> {
    Ok(a * b)
}

pub fn hamming_py(_: Python, a: i32, b: i32) -> PyResult<i32> {
    Ok((a ^ b).count_ones() as i32)
}


