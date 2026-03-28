struct EString {
    char* m_data;
    EString& operator=(char* str);
    void FixTrailingSlash(void);
};

char* FixSlash(char* dest, char* src);

void EString::FixTrailingSlash(void) {
    char buf[264];
    char* result = FixSlash(buf, m_data);
    operator=(result);
}
