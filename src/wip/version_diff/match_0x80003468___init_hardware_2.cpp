// __init_hardware
// Address: 0x80003468 | Size: 36 bytes
// Pattern: mflr r31 → bl ×3 → mtlr r31 → blr
// Dolphin SDK initialization function

extern "C" {
    void __init_user(void);
    void __init_cpp(void);
    void __init_cpp_exceptions(void);
}

void __init_hardware(void) {
    __init_user();
    __init_cpp();
    __init_cpp_exceptions();
}
