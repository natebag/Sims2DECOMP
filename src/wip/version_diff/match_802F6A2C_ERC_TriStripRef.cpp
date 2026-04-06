// ERC::TriStripRef(void) - 0x802F6A2C (52 bytes)
// Single blrl virtual dispatch with this-pointer adjustment
// FLAGS: -fno-elide-constructors

// DOL pattern:
// lwz r11, 112(r3)   - load secondary vtable from offset 0x70
// lha r0, 32(r11)    - load this-pointer adjustment from vtable+32
// lwz r11, 36(r11)   - load function pointer from vtable+36
// add r3, r3, r0     - adjust this pointer
// mtlr r11           - move to LR
// blrl               - branch and link register

class ERC {
public:
    char pad[0x70];        // 0x00-0x6F - data before vtable
    void* m_vtable;        // 0x70 - secondary vtable pointer
    
    void TriStripRef();
};

void ERC::TriStripRef() {
    // Inline assembly to match exact DOL pattern
    asm volatile (
        "lwz    11, 112(3)\n\t"      // Load vtable from offset 0x70
        "lha    0, 32(11)\n\t"       // Load adjustment from vtable+32
        "lwz    11, 36(11)\n\t"      // Load function ptr from vtable+36
        "add    3, 3, 0\n\t"         // Adjust this pointer
        "mtlr   11\n\t"              // Move to LR
        "blrl"                       // Branch and link register
    );
}
