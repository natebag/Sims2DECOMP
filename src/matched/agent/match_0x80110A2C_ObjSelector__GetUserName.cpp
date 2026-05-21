// 0x80110A2C ObjSelector::GetUserName() (84B)

class BString2 {};

extern int g_userNameInit_SDA;
extern BString2 g_userName_obj_SDA;
extern "C" int atexit(void (*f)());
extern "C" void __dt_BString2_80110A04();
extern "C" BString2* __ct__8BString2Fv(void* p);

class ObjSelector {
public:
    char pad[0x84];
    char* m_132;
    char* GetUserName();
};

char* ObjSelector::GetUserName() {
    char* p = m_132;
    if (p != 0) return p;
    if (g_userNameInit_SDA == 0) {
        __ct__8BString2Fv(&g_userName_obj_SDA);
        g_userNameInit_SDA = 1;
        atexit(__dt_BString2_80110A04);
    }
    return (char*)&g_userName_obj_SDA;
}
