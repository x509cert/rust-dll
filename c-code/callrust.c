#include <stdio.h>
#include <windows.h>

typedef char* (*BuildStringFn)(int);
typedef void (*FreeStringFn)(char*);

int main() {
    HMODULE hDll = LoadLibrary(TEXT("rust_dll.dll"));
    if (!hDll) {
        printf("Error loading DLL\n");
        return 1;
    }

    BuildStringFn build_string = (BuildStringFn)GetProcAddress(hDll, "build_string");
    FreeStringFn free_string = (FreeStringFn)GetProcAddress(hDll, "free_string");

    if (!build_string || !free_string) {
        printf("Error finding function\n");
        FreeLibrary(hDll);
        return 1;
    }

    char* result = build_string(42);
    printf("%s\n", result);
    free_string(result);

    FreeLibrary(hDll);
    return 0;
}
