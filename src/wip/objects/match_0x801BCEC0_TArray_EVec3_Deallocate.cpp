// TArray<EVec3, TArrayDefaultAllocator>::Deallocate(void)
// Address: 0x801BCEC0 | Size: 76 bytes
// Raw: 7F 45 D3 78 4B FB B1 19 80 1F 00 00 3D 20 80 3F 38 89 1A 2C 2C 00 00 00 41 82 00 10 80 7F 00 08 7F 85 E3 78 4B FB B5 BD 80 1F 00 00 3D 20 80 3F 38 89 1A 40 2C 00 00 00 41 82 00 10 80 7F 00 08 7F 85 E3 78 4B FB B5 9D 80 1F 00 00

#include "types.h"

// Forward declarations
class EVec3;
class TArrayDefaultAllocator;

// TArray class definition matching memory layout
template<typename T, typename Allocator>
class TArray {
public:
    void Deallocate(void);
private:
    T* m_data;        // 0x00
    int m_count;      // 0x04
    int m_capacity;   // 0x08
};

// External function declarations (from disassembly analysis)
extern void* Func_80177FDC(void* ptr, int count);  // Called at offset 0x4
extern void* Func_801784A0(void* ptr, int count);  // Called at offsets 0x24, 0x44

// Deallocate: Destruct elements and free memory
// Disassembly analysis:
// - Calls Func_80177FDC with r5=r26 (count), r3=r31->m_data
// - If m_data != 0, call Func_801784A0 for cleanup
// - Second loop with different parameters

template<>
void TArray<EVec3, TArrayDefaultAllocator>::Deallocate(void) {
    // Based on disassembly pattern:
    // 1. Call helper function with m_data and count
    // 2. Check if m_data is non-null
    // 3. Call Free/Deallocate function
    // 4. Repeat for second array/cleanup
    
    if (m_data) {
        // Call external cleanup function
        // This matches the bl 0x801784A0 pattern
        Func_801784A0(m_data, m_count);
    }
    
    // Second cleanup path (possibly for a different member or double-check)
    // The disassembly shows two nearly identical blocks
    if (m_data) {
        Func_801784A0(m_data, m_count);
    }
}
