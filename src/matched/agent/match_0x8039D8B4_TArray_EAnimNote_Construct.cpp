// 0x8039D8B4 TArray<EAnimNote, TArrayERAnimAllocator>::Construct(EAnimNote*, int) (76 B)
// FLAGS: -fno-schedule-insns

struct EString { void* m_buffer; };
struct EAnimNote { char pad[8]; EString m_string; };

extern void EString_SetToNull(EString* self);

void TArray_EAnimNote_Construct(EAnimNote* dst, int count) {
    int i = count - 1;
    if (count == 0) return;
    EString* str = (EString*)((char*)dst - 4);
    do {
        str = (EString*)((char*)str + 12);
        EString_SetToNull(str);
    } while (i-- != 0);
}
