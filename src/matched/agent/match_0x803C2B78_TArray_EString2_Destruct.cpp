// TArray<EString2, TArrayDefaultAllocator>::Destruct(EString2*, int) @ 0x803C2B78 (80B)
// FLAGS: -fno-schedule-insns
// EString2 element size = 4 (ptr++); m_buffer at offset 0.
// Dtor takes (this, m_buffer): called at 0x802D41A8.
// ptr in r30, i in r31 (opposite of ENDummy). ptr++ idiom makes r3=saved before lwz.

struct EString2_Dest {
    unsigned short* m_buffer;
};

extern "C" void EString2_release(EString2_Dest* self, unsigned short* buf);

void TArray_EString2_Destruct(EString2_Dest* ptr, int count) {
    int i = count - 1;
    if (count == 0) return;
    do {
        EString2_Dest* saved = ptr++;
        EString2_release(saved, saved->m_buffer);
    } while (i--);
}
