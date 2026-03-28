int strcmp2(const char* s1, const char* s2);

struct EAStringDataEQ2 {
    unsigned short m_refCount;
    char pad[6];
    char m_str[1];
};

struct EAStringCEQ2 {
    EAStringDataEQ2* m_data;

    int operator==(char* s) const;
};

int EAStringCEQ2::operator==(char* s) const {
    return strcmp2(m_data->m_str, s) == 0;
}
