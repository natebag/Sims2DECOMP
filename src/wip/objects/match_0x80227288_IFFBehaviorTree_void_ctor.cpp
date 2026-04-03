// IFFBehaviorTree::IFFBehaviorTree(void) void ctor - Real implementation
// Address: 0x80227288 | Size: 68 bytes (0x44)
// NEEDS VERIFICATION: Use verify_match.sh 0x80227288 68

class IFFBehaviorTree {
public:
    void *m_vtable;         // offset 0
    void *m_field4;         // offset 4
    void *m_field8;         // offset 8
    float m_floatField0x04; // offset 0x04 (within nested struct)
    float m_floatField0x08; // offset 0x08 (within nested struct)
    float m_floatValue;     // constant float value

    IFFBehaviorTree(void) {
        // Load float constant from data section
        float fconst = -6988.0f;  // lis r6, -32704; lfs f0, -6988(r6)
        
        // Initialize nested structures with float values
        // Complex field initialization pattern with stack usage
        
        // Store float constant to multiple locations
        *(float *)((char *)this + 0x04) = fconst;
        *(float *)((char *)this + 0x08) = fconst;
        
        // Store float to temporary stack location and reload
        // Pattern suggests field copying with float conversions
        
        // Load/store operations suggest dual-path initialization
        // or conditional field setup based on float values
    }
};

// ANALYSIS NOTES:
// - Float constant loading (lfs f0, -6988(r6))
// - Multiple float stores (stfs) to same offsets
// - Integer field copies with lwz/stw pairs
// - Stack temporary usage for float values
// - Pattern suggests nested struct initialization with float values
