struct EString {
    char* m_data;
    EString& operator=(char* str);
    void RemoveTrailingSlash(void);
};

char* RemoveSlash(char* dest, char* src);

void EString::RemoveTrailingSlash(void) {
    char buf[264];
    char* result = RemoveSlash(buf, m_data);
    operator=(result);
}
