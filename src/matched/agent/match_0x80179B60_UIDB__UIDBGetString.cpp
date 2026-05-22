// 0x80179B60 UIDB::UIDBGetString(char*) (80B)

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
    return rec ? (char*)rec->field_8 : 0;
}
