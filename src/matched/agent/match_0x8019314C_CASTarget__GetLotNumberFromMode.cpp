// CASTarget::GetLotNumberFromMode(int) @ 0x8019314C (40B)
// ASMPROC_replace_insn: match="cmpwi 0,3,0" replacement="cmpwi 0,3,1"
// ASMPROC_replace_insn: match="bc 4,1,.L4" replacement="bc 12,0,.L4"

struct GlobsNgh {
    char _pad[0x24];
    int m_lotIndex;
};

extern GlobsNgh* Globs_pNghResFile;

int CASTarget_GetLotNumberFromMode(int mode) {
    if (mode > 5) goto fail;
    if (mode < 1) goto fail;
    return Globs_pNghResFile->m_lotIndex + 1;
fail:
    return 9;
}
