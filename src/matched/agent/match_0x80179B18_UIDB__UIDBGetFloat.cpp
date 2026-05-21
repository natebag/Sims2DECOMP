// 0x80179B18 UIDB::UIDBGetFloat(char*) (72B)

class UIDBData {
public:
    int m_0;
    int m_4;
    float m_8;
};

extern UIDBData* UIDBFindRecord(char* name, int type);
extern char g_UIDB_default_float_803E2C24[16];

class UIDB {
public:
    static float UIDBGetFloat(char* name);
};

extern int g_UIDB_init_SDA;

float UIDB::UIDBGetFloat(char* name) {
    float result;
    UIDBData* r;
    if (g_UIDB_init_SDA == 0) goto use_default;
    r = UIDBFindRecord(name, 102);
    if (r != 0) goto use_m8;
use_default:
    result = *(float*)g_UIDB_default_float_803E2C24;
    goto end;
use_m8:
    result = r->m_8;
end:
    return result;
}
