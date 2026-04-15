// EAStringC::operator==(char*) const template — matches 2 functions:
// 0x8028fda4, 0x802b0294

struct EAStringC {
    char* m_ptr;
    int operator==(char* str) const;
};

extern int strcmp(const char*, const char*);

int EAStringC::operator==(char* str) const {
    return strcmp(m_ptr + 8, str) == 0;
}
