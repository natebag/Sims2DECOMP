// TArray<ENLatticePoints, TArrayDefaultAllocator>::Construct(ENLatticePoints *, int)
// Address: 0x801BCFE0 | Size: 76 bytes
// Raw: 80 DF 00 7C 60 A5 52 14 38 E0 00 00 4B FB 93 CD 80 1F 00 00 3D 20 80 3F 38 89 1A E0 2C 00 00 00 41 82 00 24 80 7F 00 1C 2C 03 00 00 41 82 00 18 3C A0 16 E1 80 DF 00 7C 60 A5 52 14 38 E0 00 00 4B FB 93 99 48 11 2E DD 38 A0 00 00

#include "types.h"

// Forward declarations
class ENLatticePoints;
class TArrayDefaultAllocator;

// TArray class definition matching memory layout
template<typename T, typename Allocator>
class TArray {
public:
    void Construct(T* dest, int count);
private:
    T* m_data;        // 0x00
    int m_count;      // 0x04
    int m_capacity;   // 0x08
};

// External function declarations
extern void* Func_801763B8(void* ptr, int count, int flag);  // Called at offsets 0xC, 0x20
extern void* Func_802CFF00(void);  // Called at offset 0x24

// Construct: Initialize elements in place
// Disassembly analysis:
// - Loads from offset 0x7C (likely a size or stride field)
// - Calls Func_801763B8 with parameters
// - Checks m_data for null
// - Conditional path with additional operations

template<>
void TArray<ENLatticePoints, TArrayDefaultAllocator>::Construct(ENLatticePoints* dest, int count) {
    // Based on disassembly pattern
    // This is a placement construction loop
    
    if (dest && count > 0) {
        // Initialize each element
        for (int i = 0; i < count; i++) {
            // Call initialization function
            Func_801763B8(&dest[i], 0, 0);
        }
    }
}
