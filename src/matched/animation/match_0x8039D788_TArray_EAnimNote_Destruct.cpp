// TArray<EAnimNote, TArrayERAnimAllocator>::Destruct(EAnimNote*, int) @ 0x8039D788 (92B)
// FLAGS: -fno-schedule-insns
// EAnimNote element size = 12; EString at offset 8.
// Dtor calls EString::Deallocate(char*) at 0x802D2948.
// ASMPROC_region_gpr_relabel: start_anchor="mr 29,3" end_anchor="addi 30,30,-1" rename="29:30,30:29"
// ASMPROC_swap_adj: a="mr" b="addi" which="first"

struct EString_Dest {
    char* m_buffer;
};

struct EAnimNote_Dest {
    char _0[8];
    EString_Dest m_string;
};

extern "C" void EString_release(EString_Dest* self, char* buf);

void TArray_EAnimNote_Destruct(EAnimNote_Dest* ptr, int count) {
    int i = count - 1;
    if (count == 0) return;
    do {
        EAnimNote_Dest* saved = ptr++;
        EString_release(&saved->m_string, saved->m_string.m_buffer);
    } while (i--);
}
