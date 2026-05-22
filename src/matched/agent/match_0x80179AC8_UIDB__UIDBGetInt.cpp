// 0x80179AC8 UIDB::UIDBGetInt(char*) (80B)

extern void* UIDB_g_pDB;

struct UIDBRecord {
    int field_0;
    int field_4;
    int field_8;
};

struct UIDB {
    static UIDBRecord* UIDBFindRecord(char* key, int type);
    static int UIDBGetInt(char* key);
};

int UIDB::UIDBGetInt(char* key) {
    if (!UIDB_g_pDB) return 0;
    UIDBRecord* rec = UIDB::UIDBFindRecord(key, 0x69);
    if (rec != 0) goto found;
    return 0;
found:
    return rec->field_8;
}
