use std::os::raw::c_char;
use std::ffi::CString;

#[no_mangle]
pub extern "C" fn build_string(value: i32) -> *mut c_char {
    let output = format!("Received value: {}", value);
    CString::new(output).unwrap().into_raw()
}

#[no_mangle]
pub extern "C" fn free_string(ptr: *mut c_char) {
    if ptr.is_null() { return }
    unsafe { 
        let _ = CString::from_raw(ptr); 
    };  // This will free the string, too
}

// this function does not use #[no_mangle] and will not be exported from the DLL
pub extern "C" fn this_is_mangled(value: i32) -> i32 {
    value * 2
}