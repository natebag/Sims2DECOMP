// dummyTrace(char *, ...)
// Address: 0x803A0524 | Size: 76 bytes
// Pattern: Varargs stub - saves all register arguments but does nothing

extern "C" void dummyTrace(const char* fmt, ...) {
    // No-op trace function - arguments are ignored
    // The compiler generates the standard varargs prologue that saves
    // r3-r10 and f1-f8 to the stack, then immediately returns
}
