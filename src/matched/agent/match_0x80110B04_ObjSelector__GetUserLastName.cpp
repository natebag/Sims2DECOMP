// 0x80110B04 ObjSelector::GetUserLastName() (84B) — twin of GetUserName

class BString2 {};

extern int g_userLastNameInit_SDA;
extern BString2 g_userLastName_obj_SDA;
extern "C" int atexit(void (*f)());
extern "C" void __dt_BString2_80110ADC();
extern "C" BString2* __ct__8BString2Fv(void* p);

class ObjSelector {
public:
    char pad[0x88];
    char* m_136;
    char* GetUserLastName();
};

char* ObjSelector::GetUserLastName() {
    char* p = m_136;
    if (p != 0) return p;
    if (g_userLastNameInit_SDA == 0) {
        __ct__8BString2Fv(&g_userLastName_obj_SDA);
        g_userLastNameInit_SDA = 1;
        atexit(__dt_BString2_80110ADC);
    }
    return (char*)&g_userLastName_obj_SDA;
}
