// 0x8019B7B0 (124B) CASFashionTarget::GetVariable(char*)
// UIDBGetString + wcslen + UCS2ToUTF8 fill for matching key.

typedef unsigned short wchar_t;

char* SimsAptMalloc(unsigned int size);
extern "C" int strcmp(const char*, const char*);
extern int wcslen(const wchar_t*);

class UIDB {
public:
    static wchar_t* UIDBGetString(char*);
};

void UCS2ToUTF8(wchar_t* src, int len, char* dst);

class CASFashionTarget {
public:
    char* GetVariable(char* key);
};

char* CASFashionTarget::GetVariable(char* key) {
    char* buf = SimsAptMalloc(32);
    buf[0] = 0;
    if (strcmp("CAS_cfc_getModList", key) == 0) {
        wchar_t* s = UIDB::UIDBGetString("CAS_cfcModListStr");
        int len = wcslen(s);
        UCS2ToUTF8(s, len + 1, buf);
    }
    return buf;
}
