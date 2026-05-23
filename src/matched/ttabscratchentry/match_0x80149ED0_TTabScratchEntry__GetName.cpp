// 0x80149ED0 TTabScratchEntry::GetName() (76B)

class BString2 {
public:
    BString2();
    char* c_str() const;
};

extern int g_bstring_init_SDA;
extern BString2 g_bstring_inst_SDA;

extern "C" int atexit(void (*f)());
extern "C" void __dt_BString2_801592C4();
extern "C" BString2* __ct__8BString2Fv(void* p);

class TTabScratchEntry {
public:
    char* GetName();
};

char* TTabScratchEntry::GetName() {
    if (g_bstring_init_SDA == 0) {
        __ct__8BString2Fv(&g_bstring_inst_SDA);
        g_bstring_init_SDA = 1;
        atexit(__dt_BString2_801592C4);
    }
    return g_bstring_inst_SDA.c_str();
}
