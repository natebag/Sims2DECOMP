// 0x802E0E90 (36B) EMemoryReadStream::EMemoryReadStream(void*)
// FLAGS: -fno-schedule-insns
// SN mr r11,r3 alias: insert mr 11,3 before li r0,0; rewrite all (3) stores to (11).
// ASMPROC_nop_before: match="li 0,0"
// ASMPROC_replace_insn: match="nop" replacement="mr 11,3"
// ASMPROC_replace_insn: match="stw 9,24(3)" replacement="stw 9,24(11)"
// ASMPROC_replace_insn: match="stw 4,28(3)" replacement="stw 4,28(11)"
// ASMPROC_replace_insn: match="stw 0,32(3)" replacement="stw 0,32(11)"
// ASMPROC_replace_insn: match="stw 0,0(3)" replacement="stw 0,0(11)"

extern int EMemoryReadStream_vtable[];

struct EMemoryReadStream {
    int m_0;
    char pad[20];
    int m_24;
    int m_28;
    int m_32;
    EMemoryReadStream(void* p);
};

EMemoryReadStream::EMemoryReadStream(void* p) {
    EMemoryReadStream* obj = this;
    *(volatile int*)&obj->m_24 = (int)EMemoryReadStream_vtable;
    *(volatile int*)&obj->m_28 = (int)p;
    *(volatile int*)&obj->m_32 = 0;
    *(volatile int*)&obj->m_0 = 0;
}
