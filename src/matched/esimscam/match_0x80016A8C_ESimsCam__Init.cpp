// FLAGS: -fno-schedule-insns
// ASMPROC_region_gpr_relabel: start_anchor="lwz 9" start_mode=at end_anchor="blr" end_mode=before rename="9:0,0:9" unsafe_clobber=true
// ASMPROC_replace_insn: match="li 9, 9" replacement="li 9,0"

struct ESimsCam {
    void Init();
};

void ESimsCam::Init() {
}
