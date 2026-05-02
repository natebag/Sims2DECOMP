// 0x800A4870 (128B) BString2::assignDebug(char*)
// Null-guarded string conversion via localConvertToWide.

extern char g_defaultDebugString[] __attribute__((section(".data")));

extern "C" {
    unsigned int strlen(const char* s);
}

extern void* __builtin_vec_new(unsigned int size);
extern void __builtin_vec_delete(void* p);
extern void localConvertToWide(wchar_t* dst, const char* src);

struct BString2 {
    void assign(wchar_t* s);
    BString2* assignDebug(const char* str);
};

BString2* BString2::assignDebug(const char* str) {
    str = str ? str : g_defaultDebugString;
    unsigned int len = strlen(str);
    wchar_t* buf = (wchar_t*)__builtin_vec_new((len + 1) * 2);
    localConvertToWide(buf, str);
    assign(buf);
    if (buf) {
        __builtin_vec_delete(buf);
    }
    return this;
}
