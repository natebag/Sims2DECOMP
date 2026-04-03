// IFFBehaviorTree::IFFBehaviorTree(int) int ctor - Real implementation
// Address: 0x802272CC | Size: 96 bytes (0x60)
// NEEDS VERIFICATION: Use verify_match.sh 0x802272CC 96

class IFFBehaviorTree {
public:
    void *m_vtable;
    void *m_field4;
    void *m_dataPtr;

    IFFBehaviorTree(int param) {
        // Stack-based float temporary handling
        float tempFloat = 0.0f;
        
        // Store and reload float through stack
        *(float *)((char *)this - 0x20) = tempFloat;
        
        // Load fields from parameter structure
        void *field1 = *(void **)((char *)&param + 0x20);
        void *field2 = *(void **)((char *)&param + 8);
        int field3 = *(int *)((char *)&param + 4);
        
        // Initialize fields
        *(int *)((char *)this + 4) = field3;
        *(void **)((char *)this + 4) = field2;
        *(void **)((char *)this + 8) = field1;
        
        // Call base constructor/initializer at 0x8022877C
        // This likely initializes parent class or does additional setup
    }
};

// ANALYSIS NOTES:
// - Float conversion pattern (stfs/lwz combination)
// - Stack temporary for float-to-int conversion
// - Parameter structure extraction (offset 0x20, 0x08, 0x04)
// - Call to initializer at 0x8022877C (likely parent ctor)
// - Simple field assignment after extraction
