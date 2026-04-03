// ObjectDataBehaviorConstants::ObjectDataBehaviorConstants(const ObjectDataBehaviorConstants &) copy ctor
// Address: 0x80225258 | Size: 212 bytes (0xD4)
// NEEDS VERIFICATION: Use verify_match.sh 0x80225258 212

class ObjectDataBehaviorConstants {
public:
    void *m_field0;
    void *m_field4;
    float m_field0x34;  // offset 0x34
    float m_field0x38;  // offset 0x38
    void *m_field0x60;  // offset 0x60
    void *m_field0x6C;  // offset 0x6C
    void *m_field0x88;  // offset 0x88 (flag field)

    ObjectDataBehaviorConstants(const ObjectDataBehaviorConstants &src) {
        // Call base constructor at 0x802106C4
        
        // Copy from src
        void *srcField0x20 = *(void **)((char *)&src + 0x20);
        void *srcField8 = *(void **)((char *)&src + 8);
        void *srcField4 = *(void **)((char *)&src + 4);
        
        // Initialize arrays at offsets 0x60 and 0x6C
        *(void **)((char *)this + 0x60) = srcField0x20;
        *(void **)((char *)this + 0x60 + 8) = srcField8;
        *(void **)((char *)this + 0x60 + 4) = srcField4;
        
        // Load float constant from 0x80400000-7280 (lis r9, -32704; lfs f13, -7280(r9))
        float fconst = -7280.0f;  // Placeholder - actual value from data section
        
        // Load fields 0x34 and 0x38 for float comparison
        float field0x34 = *(float *)((char *)this + 0x34);
        float field0x38 = *(float *)((char *)this + 0x38);
        
        // Initialize second array block
        *(void **)((char *)this + 0x6C) = *(void **)((char *)this + 0x20);
        *(void **)((char *)this + 0x6C + 8) = srcField8;
        *(void **)((char *)this + 0x6C + 4) = srcField4;
        
        // Conditional branching based on float comparisons
        if (field0x34 != 0.0f) {
            // Branch 1: Store float values to stack and call helper
            float tempVal = -7276.0f;
            void *field4 = *(void **)((char *)this + 4);
            // Call helper at 0x80210C58
        } else if (field0x38 != 0.0f) {
            // Branch 2: Load field4 and call helper with different params
            void *field4 = *(void **)((char *)this + 4);
            void *field0x34Ptr = (void *)((char *)this + 0x34);
            // Call helper at 0x80210C58
        } else {
            // Branch 3: Construct from offset 8
            void *src8 = (void *)((char *)this + 8);
            void *field0x34Ptr = (void *)((char *)this + 0x34);
            // Call helper at 0x80210C58
        }
        
        // Update flag at offset 0x88
        int flags = *(int *)((char *)this + 0x88);
        // Mask with 0x000007FA and store back
        *(int *)((char *)this + 0x88) = flags & 0x000007FA;
    }
};

// ANALYSIS NOTES:
// - Call to base class constructor at entry
// - Complex field replication from source
// - Floating-point conditional logic (multiple branches on float comparisons)
// - Three distinct code paths based on field0x34 and field0x38 values
// - Helper function calls at 0x80210C58 with varying parameters
// - Flag field manipulation with bitmask (0x000007FA)
// - Total of 2 float fields involved in branching logic
