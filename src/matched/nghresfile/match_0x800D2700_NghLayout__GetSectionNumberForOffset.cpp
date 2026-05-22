// 0x800D2700 NghLayout::GetSectionNumberForOffset(unsigned int) (68B)
// FLAGS: -fno-schedule-insns
//
// do-while formulation folds early-exit returns into end-of-function
// return-0 block; compiler emits bc->.L3 for the first two exits,
// which ASMPROC_replace_insn patches to bclr (blelr/bltlr).

// ASMPROC_replace_insn: match="bc 4,1,.L3" replacement="bclr 4,1"
// ASMPROC_replace_insn: match="bc 12,0,.L3" replacement="bclr 12,0"

struct NghLayout {
    int m_field_0;
    int m_field_4;
    int m_field_8;
    int m_numSubSections;
    int m_totalSize;
    int m_numSections;
    int GetSectionNumberForOffset(unsigned int offset);
};

struct Section {
    int field_0;
    int field_4;
    int field_8;
    int field_C;
    int field_10;
    int field_14;
};

int NghLayout::GetSectionNumberForOffset(unsigned int offset) {
    Section* s = (Section*)m_field_4;
    int result = 0;
    if (s->field_4 > 0) {
        offset -= s->field_C;
        if ((int)offset >= 0) {
            do {
                s++;
                result++;
                if (s->field_4 <= 0) break;
                offset -= s->field_C;
            } while ((int)offset >= 0);
            return result;
        }
    }
    return 0;
}
