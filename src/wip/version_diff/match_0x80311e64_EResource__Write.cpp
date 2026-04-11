struct EStream;
struct EString {
    int m_data;
    EString(char*);
};
extern char gpResName_empty[];
extern EStream& operator<<(EStream&, EString&);
extern void EString__Deallocate_char_ptr(EString*, char*);
struct EResource {
    void Write(EStream&);
};
void EResource::Write(EStream& s) {
    EString str(gpResName_empty);
    operator<<(s, str);
    char* old = (char*)str.m_data;
    EString__Deallocate_char_ptr(&str, old);
}
