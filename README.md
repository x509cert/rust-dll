# rust-dll
Super simple code that shows how to call a DLL written in Rust from C code. The reason for doing this is to help people 
understand how then can start to move from C/C++ to Rust by implementing new functionality in Rust as a DLL and then calling
the DLL from current C/C++ code. 

In this example, you can verify the DLL exports functions correctly using dumpbin:

dumpbin .\rust_dll.dll /exports
Microsoft (R) COFF/PE Dumper Version 14.38.33030.0
Copyright (C) Microsoft Corporation.  All rights reserved.

Dump of file .\rust_dll.dll

File Type: DLL

  Section contains the following exports for rust_dll.dll

    00000000 characteristics
    FFFFFFFF time date stamp
        0.00 version
           1 ordinal base
           2 number of functions
           2 number of names

    ordinal hint RVA      name

          1    0 00001040 build_string = build_string
          2    1 000011E0 free_string = free_string

The code is in two parts:

- The Rust DLL code which is built with cargo build, note the use of lib.rs rather than main.rs.
- The calling code written in C, built using cl callrust.c

The .exe and .dll must be in the same folder, or the DLL along the search path. 

