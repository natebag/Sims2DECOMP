// TArray<ECharacterNode, TArrayERCharacterAllocator>::Destruct(ECharacterNode*, int) @ 0x803C99BC (112B)
// FLAGS: -fno-schedule-insns
// ECharacterNode element size = 184; TArray<int> at offset 4, EString at offset 180.
// Dtor calls EString::Deallocate(char*) at 0x802D2948 and TArray<int>::~TArray at 0x803C997C.
// ASMPROC_region_gpr_relabel: start_anchor="mr 28,3" end_anchor="addi 29,29,-1" rename="28:29,29:28,30:31,31:30"
// ASMPROC_swap_adj: a="mr" b="addi" which="first"
// ASMPROC_swap_adj: a="addi" b="addi" which="first"

struct EString_Dest {
    char* m_buffer;
};

template <class T, class Alloc>
class TArray {
public:
    T* m_data;
    int m_size;
    int m_capacity;
    ~TArray();
};

struct TArrayERCharacterAllocator {};

struct ECharacterNode_Dest {
    char _0[4];
    TArray<int, TArrayERCharacterAllocator> m_array;
    char _pad[164];
    EString_Dest m_string;
};

extern "C" void EString_release(EString_Dest* self, char* buf);

void TArray_ECharacterNode_Destruct(ECharacterNode_Dest* ptr, int count) {
    int i = count - 1;
    if (count == 0) return;
    do {
        ECharacterNode_Dest* saved = ptr++;
        EString_release(&saved->m_string, saved->m_string.m_buffer);
        saved->m_array.~TArray();
    } while (i--);
}
