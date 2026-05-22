// 0x80179BB0 UIDB::UIDBSetInt(char*, int) (96B)
// ASMPROC_replace_insn: match="bc 12,2,.L4" replacement="bc 4,2,.L4_found"
// ASMPROC_replace_insn: match="stw 31,8(3)" replacement="li 3,0" occurrence=0
// ASMPROC_replace_insn: match="li 3,1" replacement="b .L6" occurrence=0
// ASMPROC_replace_insn: match="b .L6" replacement="stw 31,8(3)" occurrence=1
// ASMPROC_replace_insn: match="stw 31,8(3)" replacement=".L4_found: stw 31,8(3)" occurrence=0
// ASMPROC_replace_insn: match="li 3,0" replacement="li 3,1" occurrence=2

extern void* UIDB_g_pDB;

struct UIDBRecord {
    int field_0;
    int field_4;
    int field_8;
};

struct UIDB {
    static UIDBRecord* UIDBFindRecord(char* key, int type);
    static int UIDBSetInt(char* key, int value);
};

int UIDB::UIDBSetInt(char* key, int value) {
    if (!UIDB_g_pDB) return 0;
    UIDBRecord* rec = UIDB::UIDBFindRecord(key, 0x69);
    if (rec == 0) return 0;
    rec->field_8 = value;
    return 1;
}
