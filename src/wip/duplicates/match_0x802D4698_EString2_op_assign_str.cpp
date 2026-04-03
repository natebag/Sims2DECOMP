struct EString2 {
    char* m_data;
    void clearChar(void);
    void assignChar(char* str);
    EString2& operator=(char* str);
};

EString2& EString2::operator=(char* str) {
    char* old = m_data;
    clearChar();
    assignChar(old);
    return *this;
}
