// 0x800B8C88 (44B) cIGZSndSys::CreateInstance(void)

struct cIGZSndSys {
    char data[1052];
    cIGZSndSys();
    static cIGZSndSys* CreateInstance();
};

extern cIGZSndSys* g_sndsys;

cIGZSndSys* cIGZSndSys::CreateInstance() {
    cIGZSndSys* p = new cIGZSndSys();
    g_sndsys = p;
    return p;
}
