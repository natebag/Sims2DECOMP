struct EFile;
struct EString {
    int m_data;
};
struct ETypeInfo {
    char _pad[0x16];
    unsigned short m_readVersion;
};
extern ETypeInfo gTypeInfo_EResource;
extern void EString__SetToNull_void(EString*);
extern void EString__Deallocate_char_ptr(EString*, char*);
extern EFile& operator>>(EFile&, EString&);
struct EResource {
    void Load(EFile&);
};
void EResource::Load(EFile& f) {
    EString str;
    EString__SetToNull_void(&str);
    if (gTypeInfo_EResource.m_readVersion == 0) {
        operator>>(f, str);
    }
    char* old = (char*)str.m_data;
    EString__Deallocate_char_ptr(&str, old);
}
