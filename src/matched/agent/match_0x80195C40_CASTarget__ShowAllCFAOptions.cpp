// ASMPROC_replace_insn: match="cmpwi 7,0,1" replacement="cmpwi 0,0,2"
// ASMPROC_replace_insn: match="bc 12,29,.L6" replacement="bc 4,0,.L6"
// ASMPROC_inject_before: before="bc 12,30,.L9" lines="cmpwi 0,0,1"
// ASMPROC_replace_insn: match="bc 12,30,.L9" replacement="bc 12,2,.L9"
// 0x80195C40 (64B) CASTarget::ShowAllCFAOptions()

struct CASTarget {
    char pad_0[0x104];
    int  m_mode;
    int  ShowAllCFAOptions();
};

int CASTarget::ShowAllCFAOptions() {
    int mode = m_mode;
    if (mode > 4) goto high;
    if (mode >= 2) goto ret_false;
    if (mode == 0) goto ret_false;
    if (mode == 1) goto ret_true;
    goto ret_false;
high:
    if (mode != 5) goto ret_false;
ret_true:
    return 1;
ret_false:
    return 0;
}
