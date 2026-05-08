// EFixedString::MakeCopy(char) - 0x802C75E8 (28B)
// FLAGS: -fno-schedule-insns -fno-elide-constructors
// ASMPROC_insert_mr: before="lwz 9,0(3)" src=3 dst=11 relabel=3:11
// ASMPROC_swap_adj: a=lwz b=li which=first
// ASMPROC_force_reg_at_pos: match="lwz 9, 0(11)" pos=0 from_reg=9 to_reg=10 occurrence=0
// ASMPROC_force_reg_at_pos: match="stb 4,0(9)" pos=1 from_reg=9 to_reg=10
// ASMPROC_force_reg_at_pos: match="lwz 11, 0(11)" pos=0 from_reg=11 to_reg=9
// ASMPROC_force_reg_at_pos: match="stb 0,1(11)" pos=1 from_reg=11 to_reg=9

struct EFixedString {
    char* m_pBuffer;
    int m_nMaxSize;

    void MakeCopy(char c);
};

void EFixedString::MakeCopy(char c) {
    EFixedString* p = this;
    p->m_pBuffer[0] = c;
    p->m_pBuffer[1] = '\0';
}
