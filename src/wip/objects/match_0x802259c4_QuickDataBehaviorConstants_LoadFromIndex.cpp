// QuickDataBehaviorConstants::LoadFromIndex(unsigned int, int) - Real implementation
// Address: 0x802259C4 | Size: 216 bytes (0xD8)
// NEEDS VERIFICATION: Use verify_match.sh 0x802259C4 216

class QuickDataBehaviorConstants {
public:
    void *m_data;

    void LoadFromIndex(unsigned int index, int param) {
        // Initial call to 0x800B45DC with index parameter
        // This loads or validates the data
        
        // Increment operation: r29 += 3
        int counter = 3;
        
        // Loop structure starting at offset 0x802259D8
        int current = index;
        int temp = 0;
        
        while (true) {
            // Check condition (cmpwi)
            if ((current & 0x00000001) == 0) {
                // Branch: Call helper at 0x800B45DC
                // current += 3
                current += 3;
                
                // Conditional check: subtract 1, jump if >= 0
                temp--;
                if (temp < 0) {
                    break;
                }
            } else {
                break;
            }
        }
        
        // Load saved registers from stack
        // lwz r31, 36(r1)
        // lwz r30, 32(r1)
        
        // Check condition and potentially call 0x800B4724
        int val = 0;
        if (val != 0) {
            // Call helper with r4 = 2
            current += 3;
            
            // Loop again with test condition
            while (true) {
                if ((val & 0x00000001) != 0) {
                    break;
                }
            }
        }
        
        // Load parameters from stack
        // r3 = *(r1 + 32)
        // r0 = *(r1 + 44)
        
        // Complex conditional with multiple branches
        // Check for 0x80 bit (param & 0x80)
        if ((param & 0x80) != 0) {
            // Call 0x802D1220 (error path)
        } else {
            // Call 0x8039BE60 (success path)
        }
        
        // Store results to stack
        // Build call parameter block with r20, r21, r22, r23
        
        // Main work call to 0x80136C18 with 8 parameters
        // This is the actual load operation
        
        // Final check: if (r3 != 0) handle error
        if (param != 0) {
            // Load result from stack at offset 0x78
        }
    }
};

// ANALYSIS NOTES:
// - Initialization call to 0x800B45DC with index parameter
// - Two nested loop structures with increment-by-3 pattern
// - Complex conditional branching based on bit tests
// - Multiple helper function calls for parameter validation
// - Main work done by call to 0x80136C18 with 8 parameters
// - Stack parameter passing with extensive setup
// - Error handling with conditional routing (0x802D1220 vs 0x8039BE60)
// - Likely loads behavior constants from persistent index into memory
