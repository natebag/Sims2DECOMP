// 0x802D5770 EString2::MakeLegalFilename() (128B)
// ASMPROC_region_gpr_relabel: start_anchor="lwz 3,0(3)" start_mode=at end_anchor="addi 3,3,2" end_mode=at rename="3:9,9:11"
// ASMPROC_replace_insn: match="cmpwi 0,0,33" replacement="cmpwi 0,0,34"
// ASMPROC_replace_insn: match="bc 12,1,.L7" replacement="bc 4,0,.L7" occurrence=0
// ASMPROC_replace_insn: match="cmpwi 0,0,61" replacement="cmpwi 0,0,62"
// ASMPROC_replace_insn: match="bc 12,1,.L7" replacement="bc 4,0,.L7" occurrence=0
typedef unsigned short wchar_t_u;

struct EString2_MLF {
    wchar_t_u *m_str;
    void MakeLegalFilename(void);
};

void EString2_MLF::MakeLegalFilename(void) {
    wchar_t_u *p = m_str;
    for (;;) {
        int c = *p;
        if (c == ':') goto do_store;
        if (c > ':') goto above_colon;
        // c < ':'
        if (c > '#') goto hash_to_colon;
        // c <= '#'
        if (c >= '"') goto do_store;
        // c < '"'
        if (c == 0) return;
        goto do_next;

    hash_to_colon:
        if (c == '*') goto do_store;
        if (c == '/') goto do_store;
        goto do_next;

    above_colon:
        if (c > '?') goto above_q;
        // c in 59..63
        if (c >= '>') goto do_store;
        if (c == '<') goto do_store;
        goto do_next;

    above_q:
        if (c == '\\') goto do_store;
        if (c != '|') goto do_next;

    do_store:
        *p = '_';
    do_next:
        p++;
    }
}
