// 0x80179BB0 UIDB::UIDBSetInt(char*, int) (96B)

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
    if (rec != 0) goto found;
    return 0;
found:
    rec->field_8 = value;
    return 1;
}
