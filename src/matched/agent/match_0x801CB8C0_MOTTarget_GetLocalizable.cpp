// 0x801CB8C0 (132B) MOTTarget::GetLocalizable(char*)
// Sibling of ACTTarget::GetLocalizable — 8192-byte wchar_t temp +
// UIQDSubstitutionStrings fill + 3 wcslen probes + alloc result via
// (len+1)*2 + wcscpy + free temp.

typedef unsigned short wchar_t;

char* SimsAptMalloc(unsigned int size);
void SimsAptFree(void*);
extern "C" int isdigit(int);
extern int wcslen(const wchar_t*);
extern wchar_t* wcscpy(wchar_t*, const wchar_t*);

class UIQDTarget {
public:
    static void UIQDSubstitutionStrings(wchar_t*);
};

class MOTTarget {
public:
    wchar_t* GetLocalizable(char* key);
};

wchar_t* MOTTarget::GetLocalizable(char* key) {
    isdigit((signed char)key[0]);
    wchar_t* temp = (wchar_t*)SimsAptMalloc(8192);
    *(short*)temp = 0;
    wcslen(temp);
    UIQDTarget::UIQDSubstitutionStrings(temp);
    wcslen(temp);
    int len = wcslen(temp);
    wchar_t* result = (wchar_t*)SimsAptMalloc((len + 1) * 2);
    wcscpy(result, temp);
    SimsAptFree(temp);
    return result;
}
