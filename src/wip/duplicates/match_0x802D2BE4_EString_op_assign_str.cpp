struct EString {
    char* m_data;
    void clear(void);
    void assign(char* str);
    EString& operator=(char* str);
};

EString& EString::operator=(char* str) {
    char* old = m_data;
    clear();
    assign(old);
    return *this;
}
