// 0x80179B18 UIDB::UIDBGetFloat(char*) (72B)

extern void* UIDB_g_pDB;
extern float UIDB_g_floatDefault[4];

struct UIDBRecord {
    int field_0;
    int field_4;
    int field_8;
};

struct UIDB {
    static UIDBRecord* UIDBFindRecord(char* key, int type);
    static float UIDBGetFloat(char* key);
};

float UIDB::UIDBGetFloat(char* key) {
    UIDBRecord* rec;
    if (!UIDB_g_pDB) goto return_default;
    rec = UIDB::UIDBFindRecord(key, 0x66);
    if (rec != 0) goto found;
return_default:
    return UIDB_g_floatDefault[0];
found:
    return *(float*)&rec->field_8;
}
