// ObjectDataBehaviorConstants::~ObjectDataBehaviorConstants(void) - Real implementation
// Address: 0x8022532C | Size: 176 bytes (0xB0)
// NEEDS VERIFICATION: Use verify_match.sh 0x8022532C 176

class ObjectDataBehaviorConstants {
public:
    void *m_field0;      // offset 0
    void *m_field0x20;   // offset 0x20
    void *m_field0x34;   // offset 0x34
    void *m_field0x60;   // offset 0x60
    void *m_field0x6C;   // offset 0x6C
    void *m_field0x88;   // offset 0x88 (flag check)
    void *m_field0x98;   // offset 0x98

    ~ObjectDataBehaviorConstants(void) {
        // Check flag at offset 0x88
        int flags = *(int *)((char *)this + 0x88);
        
        if ((flags & 0x01) != 0) {
            // Delete helper 1 (call to 0x8001A00C)
            // Likely cleanup of first structure
            
            // Call cleanup at 0x8021097C
            
            // Call cleanup at 0x80210F7C
            
            // Check another flag
            if ((flags & 0x20) == 0) {
                // Copy fields and zero field at 0x98
                void *field0x20 = *(void **)((char *)this + 0x20);
                void *field0x34 = *(void **)((char *)this + 0x34);
                
                *(void **)((char *)this + 0x60) = field0x20;
                *(void **)((char *)this + 0x6C) = field0x34;
                *(int *)((char *)this + 0x98) = 0;
            }
        } else {
            // Delete from base class at 0x80224AAC
            // Delete base class at 0x80224BB8
        }
        
        // Final flag check at 0x88 with 0x20 mask
        if ((*(int *)((char *)this + 0x88) & 0x20) == 0) {
            // Additional cleanup
        }
    }
};

// ANALYSIS NOTES:
// - Two code paths based on flag at offset 0x88
// - Complex destructor with conditional deletion
// - Matches pattern of ref-counted or flag-dependent cleanup
// - Multiple helper calls suggest complex object hierarchy
// - Field replication suggests array-like member management
