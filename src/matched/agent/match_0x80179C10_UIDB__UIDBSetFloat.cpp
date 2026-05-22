// 0x80179C10 UIDB::UIDBSetFloat(char*, float) (88B)

extern void* UIDB_g_pDB;

struct UIDBRecord {
    int field_0;
    int field_4;
    int field_8;
};

struct UIDB {
    static UIDBRecord* UIDBFindRecord(char* key, int type);
    static int UIDBSetFloat(char* key, float value);
};

int UIDB::UIDBSetFloat(char* key, float value) {
    if (!UIDB_g_pDB) return 0;
    UIDBRecord* rec = UIDB::UIDBFindRecord(key, 0x66);
    if (rec) *(float*)&rec->field_8 = value;
    return 1;
}
