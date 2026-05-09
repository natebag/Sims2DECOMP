// 0x800A75BC (44B) QuickStringSet::QuickStringSet(void)
// (no FLAGS override — default GCC scheduling)
// SN scheduler: hoists li r0,0 before la@l (hides load latency), and hoists
// SDA load before stw vtable. Two cyclic swaps via 4-directive ASMPROC.
// ASMPROC_replace_insn: match="la 9,vt_QuickStringSet@l(9)" replacement="li 0,0"
// ASMPROC_replace_insn: match="li 0,0" replacement="la 9,vt_QuickStringSet@l(9)" occurrence=1
// ASMPROC_replace_insn: match="stw 9,0(11)" replacement="la 10,sda_QuickStringSet_global@sda21(0)"
// ASMPROC_replace_insn: match="la 10,sda_QuickStringSet_global@sda21(0)" replacement="stw 9,0(11)" occurrence=1

extern char vt_QuickStringSet[];
extern int sda_QuickStringSet_global;

struct QuickStringSet {
    void* m_vt;
    int m_4;
    int m_8;
    int* m_12;
    int m_16;
    QuickStringSet();
};

QuickStringSet::QuickStringSet() {
    QuickStringSet* p = this;
    *(void* volatile*)&p->m_vt = vt_QuickStringSet;
    *(volatile int*)&p->m_8 = 0;
    *(int* volatile*)&p->m_12 = &sda_QuickStringSet_global;
    *(volatile int*)&p->m_16 = 0;
    *(volatile int*)&p->m_4 = 0;
}
