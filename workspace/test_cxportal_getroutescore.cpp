// 0x80132788 cXPortalImpl::GetRouteScore(short) (64B)
// FLAGS: -fno-schedule-insns
// ASMPROC_gpr_relabel: swap="4:11"
// ASMPROC_replace_insn: match="mr. 4,11" replacement="mr. 4,4"
// ASMPROC_replace_insn: match="slwi 9,4,2" replacement="addi 9,4,-1"
// ASMPROC_replace_insn: match="add 9,9,11" replacement="slwi 9,9,2"
// ASMPROC_replace_insn: match="lfs 1,-4(9)" replacement="lfsx 1,11,9"
extern float kBadRouteScore[3];
struct cXPortalImpl {
    char _pad[8];
    float* m_begin;
    float* m_end;
    float GetRouteScore(short n) const;
};
float cXPortalImpl::GetRouteScore(short n) const {
    if (n > 0) {
        float* begin = m_begin;
        unsigned int idx = (unsigned short)n;
        float* end = m_end;
        int count = (int)((char*)end - (char*)begin) >> 2;
        if ((unsigned int)idx <= (unsigned int)count) {
            return begin[n - 1];
        }
    }
    return kBadRouteScore[0];
}
