// #[no_mangle] keeps Rust from "mangling" the name of the exported functoin
// extern "C" means to use the C ABI to expose this function, allowing C# to pull it in

#[no_mangle]
pub extern "C" fn multiply(a: i32, b: i32) -> i32 {
    a * b
}

#[no_mangle]
pub extern "C" fn hamming_distance(a: u32, b: u32) -> u32 {
    (a ^ b).count_ones()
}
