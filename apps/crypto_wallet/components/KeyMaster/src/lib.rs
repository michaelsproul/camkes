#![feature(compiler_builtins_lib)]
#![no_std]

use core::panic::PanicInfo;

#[allow(dead_code)]
#[no_mangle]
extern "C" {
    fn printf(val: *const u8);
}

// This is the camkes entry point for this app
#[no_mangle]
pub extern "C" fn hello_world() {
    unsafe {
        printf(b"Hello, world!!\n\0" as *const u8)
    }
}

#[panic_handler]
// #[no_mangle]
pub fn panic(_info: &PanicInfo) -> ! {
    unsafe {
        printf(b"Panicked\n\0" as *const u8)
    }
    loop {}
}
