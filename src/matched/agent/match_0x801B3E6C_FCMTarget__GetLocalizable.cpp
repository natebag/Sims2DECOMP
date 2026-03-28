/* FCMTarget::GetLocalizable(char *) at 0x801B3E6C (132b) */

typedef unsigned short wchar_t;

extern int toupper(int);
extern void* operator_new_array(unsigned int);
extern void operator_delete_array(void*);
extern int wcslen(const wchar_t*);
extern wchar_t* wcscpy(wchar_t*, const wchar_t*);

extern void GetLocalizableString(wchar_t*);

struct FCMTarget {
    wchar_t* GetLocalizable(char* key);
};

wchar_t* FCMTarget::GetLocalizable(char* key) {
    toupper((signed char)key[0]);
    wchar_t* temp = (wchar_t*)operator_new_array(8192);
    *(short*)temp = 0;
    wcslen(temp);
    GetLocalizableString(temp);
    wcslen(temp);
    int len = wcslen(temp);
    wchar_t* result = (wchar_t*)operator_new_array((len + 1) * 2);
    wcscpy(result, temp);
    operator_delete_array(temp);
    return result;
}
