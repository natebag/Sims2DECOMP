/* ITBTarget::GetLocalizable(char *) at 0x801BD3C8 (200b) */

typedef unsigned short wchar_t;

extern int toupper(int);
extern void* operator_new_array(unsigned int);
extern void operator_delete_array(void*);
extern int wcslen(const wchar_t*);
extern wchar_t* wcscpy(wchar_t*, const wchar_t*);
extern char* strcmp_table(char*, char*);
extern wchar_t* GetNameString(void*);
extern void GetLocalizableString(wchar_t*);

extern char g_itbTable[];

struct ITBTarget {
    char pad[0x8C];
    void* m_nameRef;

    wchar_t* GetLocalizable(char* key);
};

wchar_t* ITBTarget::GetLocalizable(char* key) {
    if (toupper((signed char)key[0]) != 0) {
        key++;
    }
    wchar_t* temp = (wchar_t*)operator_new_array(8192);
    *(short*)temp = 0;
    if (strcmp_table(g_itbTable, key) == 0) {
        wchar_t* name = GetNameString(m_nameRef);
        wcscpy(temp, name);
    }
    wcslen(temp);
    GetLocalizableString(temp);
    wcslen(temp);
    int len = wcslen(temp);
    wchar_t* result = (wchar_t*)operator_new_array((len + 1) * 2);
    wcscpy(result, temp);
    operator_delete_array(temp);
    return result;
}
