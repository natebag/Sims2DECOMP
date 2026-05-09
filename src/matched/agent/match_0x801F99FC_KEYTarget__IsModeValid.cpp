// KEYTarget::IsModeValid(void) @ 0x801F99FC (32B)
// ASMPROC_swap_adj: a=cmpwi b=li which=first
// ASMPROC_swap_adj: a=bc b=li which=first
// ASMPROC_swap_adj: a=cmpwi b=li which=first
// ASMPROC_replace_insn: match="bc 12,1,.L3" replacement="bclr 12,1"
// ASMPROC_replace_insn: match="cmpwi 0,0,0" replacement="cmpwi 0,0,1"
// ASMPROC_replace_insn: match="bclr 4,1" replacement="bclr 12,0"

struct KEYTarget_IMV {
    char _pad[0x8C];
    int m_mode;
    int IsModeValid() const;
};

int KEYTarget_IMV::IsModeValid() const {
    int result = 0;
    int mode = m_mode;
    if (mode > 4) return result;
    if (mode < 1) return result;
    return 1;
}
