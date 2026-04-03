// TArray<EVec3, TArrayDefaultAllocator>::operator=(TArray<EVec3, TArrayDefaultAllocator> &)
// Address: 0x801BD264 | Size: 76 bytes
// Raw: 4B FB FF D1 3C 80 80 3F 3C E0 80 3F 38 61 00 08 38 A0 00 7D 38 C0 00 00 39 00 00 00 38 E7 DD C4 38 84 1B 38 4B FC 0E B1 38 80 00 FF 38 61 00 08 4B FC 14 99 38 61 00 08 4B FC 10 7D 38 61 00 08 38 80 00 02 4B FB FF AD 48 00 00 6C

#include "types.h"

// Forward declarations
class EVec3;
class TArrayDefaultAllocator;

// TArray class definition matching memory layout
template<typename T, typename Allocator>
class TArray {
public:
    TArray& operator=(TArray& other);
private:
    T* m_data;        // 0x00
    int m_count;      // 0x04
    int m_capacity;   // 0x08
};

// External function declarations
extern void Func_8017D234(void);  // Called at offset 0x0
extern void Func_8017E138(void* ptr, int size, int flags);  // Called at offset 0x24
extern void Func_8017E72C(void* ptr, int val);  // Called at offset 0x30
extern void Func_8017E318(void* ptr);  // Called at offset 0x38
extern void Func_8017D254(void* ptr, int count);  // Called at offset 0x44

// operator=: Assignment operator
// Disassembly analysis:
// - Calls Func_8017D234 (initialization/setup)
// - Sets up stack frame with r1+8
// - Loads constants into r4 and r7
// - Multiple function calls for copy operations
// - Final branch to 0x801BD318

template<>
TArray<EVec3, TArrayDefaultAllocator>& TArray<EVec3, TArrayDefaultAllocator>::operator=(TArray& other) {
    // Self-assignment check
    if (this == &other) {
        return *this;
    }
    
    // Setup and initialization (matches bl 0x8017D234)
    Func_8017D234();
    
    // Stack allocation and setup
    char localBuffer[8];
    
    // Copy operation sequence
    Func_8017E138(localBuffer, 125, 0);
    Func_8017E72C(localBuffer, 255);
    Func_8017E318(localBuffer);
    
    // Final assignment operation
    Func_8017D254(localBuffer, 2);
    
    // Branch to continuation (0x801BD318)
    // This would be the return or next operation
    
    return *this;
}
