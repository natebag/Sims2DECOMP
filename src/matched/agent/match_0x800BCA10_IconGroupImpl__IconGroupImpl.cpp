// 0x800BCA10 (36B) IconGroupImpl::IconGroupImpl(void)
// FLAGS: -fno-schedule-insns -fno-schedule-insns2
// SN mr r11,r3 alias: la@l removed, mr 11,3 inserted at pos 1; vtable stw
// displaced to pos 4 via nop insertion; all r3 stores rewritten to r11.
// GCC order: lis/la/stw-vt/li/stw12/stw8/stw4 (8 insns)
// DOL order: lis/mr/li/la/stw-vt/stw12/stw8/stw4 (9 insns)
// 8-directive recipe:
// ASMPROC_replace_insn: match="la 9,vt_IconGroupImpl_a@l(9)" replacement="mr 11,3"
// ASMPROC_replace_insn: match="stw 9,0(3)" replacement="li 0,0"
// ASMPROC_replace_insn: match="li 0,0" replacement="la 9,vt_IconGroupImpl_a@l(9)" occurrence=1
// ASMPROC_nop_before: match="stw 0,12(3)"
// ASMPROC_replace_insn: match="nop" replacement="stw 9,0(11)"
// ASMPROC_replace_insn: match="stw 0,12(3)" replacement="stw 0,12(11)"
// ASMPROC_replace_insn: match="stw 0,8(3)" replacement="stw 0,8(11)"
// ASMPROC_replace_insn: match="stw 0,4(3)" replacement="stw 0,4(11)"

extern char vt_IconGroupImpl_a[];

struct IconGroupImpl {
    void* m_vt;
    int m_id;
    void* m_icon;
    void* m_entry;
    IconGroupImpl();
};

IconGroupImpl::IconGroupImpl() {
    IconGroupImpl* p = this;
    p->m_vt = vt_IconGroupImpl_a;
    p->m_entry = 0;
    p->m_icon = 0;
    p->m_id = 0;
}
