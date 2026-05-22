// 0x80179B60 UIDB::UIDBGetString(char*) (80B)
// ASMPROC_replace_insn: match="bc 12,2,.L5" replacement="bc 4,2,.LNEW"
// ASMPROC_replace_insn: match="lwz 3,8(3)" replacement="li 3,0" occurrence=0
// ASMPROC_replace_insn: match=".L5:" replacement=".LNEW:"
// ASMPROC_replace_insn: match="li 3,0" replacement="lwz 3,8(3)" occurrence=2

extern void* UIDB_g_pDB;

struct UIDBRecord {
    int field_0;
    int field_4;
    int field_8;
};

struct UIDB {
    static UIDBRecord* UIDBFindRecord(char* key, int type);
    static char* UIDBGetString(char* key);
};

char* UIDB::UIDBGetString(char* key) {
    if (!UIDB_g_pDB) return 0;
    UIDBRecord* rec = UIDB::UIDBFindRecord(key, 0x73);
    if (rec != 0) goto found;
    return 0;
found:
    return (char*)rec->field_8;
}
