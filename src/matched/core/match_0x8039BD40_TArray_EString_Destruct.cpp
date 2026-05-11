// TArray<EString, TArrayDefaultAllocator>::Destruct(EString*, int) @ 0x8039BD40 (80B)
// FLAGS: -fno-schedule-insns
// EString element size = 4 (ptr++); m_buffer at offset 0.
// Dtor takes (this, m_buffer): called at 0x802D2948.

struct EString_Dest {
    char* m_buffer;
};

extern "C" void EString_release(EString_Dest* self, char* buf);

void TArray_EString_Destruct(EString_Dest* ptr, int count) {
    int i = count - 1;
    if (count == 0) return;
    do {
        EString_Dest* saved = ptr++;
        EString_release(saved, saved->m_buffer);
    } while (i--);
}
