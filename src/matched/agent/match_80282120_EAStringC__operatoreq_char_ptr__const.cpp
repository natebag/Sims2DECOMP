int strcmp(const char* s1, const char* s2);

struct EAStringData {
    unsigned short m_refCount;
    char pad[6];
    char m_str[1];
};

struct EAStringC {
    EAStringData* m_data;

    int operator==(char* s) const;
};

int EAStringC::operator==(char* s) const {
    return strcmp(m_data->m_str, s) == 0;
}
