// IFFBehaviorTree::QueryInterface(unsigned int, void **) - Real implementation
// Address: 0x8022791C | Size: 112 bytes (0x70)
// NEEDS VERIFICATION: Use verify_match.sh 0x8022791C 112

class IFFBehaviorTree {
public:
    void *m_vtable;

    int QueryInterface(unsigned int iid, void **ppv) {
        // Two code paths based on condition
        // Path 1: Call to 0x802D202C (QueryInterface helper for iid 1)
        // Path 2: Call to 0x802C67FC (QueryInterface helper for iid 2)
        
        int result = 0;
        void *resultPtr = 0;
        
        // Check which interface is requested
        if (iid == 1) {
            // Call first helper
            void (*qiHelper1)(int, void **) = (void (*)(int, void **))0x802D202C;
            qiHelper1(iid, &resultPtr);
        } else {
            // Call second helper  
            void (*qiHelper2)(int, void **) = (void (*)(int, void **))0x802C67FC;
            qiHelper2(iid, &resultPtr);
        }
        
        // Store result pointer
        if (ppv != 0) {
            *ppv = resultPtr;
        }
        
        // Return success (implicit, as r3 is loaded with this pointer)
        return (resultPtr != 0) ? 1 : 0;
    }
};

// ANALYSIS NOTES:
// - Dual-path QueryInterface pattern (two separate helper calls)
// - Conditional branching on interface ID
// - Call to 0x802D202C for one interface type
// - Call to 0x802C67FC for another interface type
// - Stack-based result passing with load/store
// - Return this pointer or derived interface pointer
// - COM standard QueryInterface for multiple interface support
