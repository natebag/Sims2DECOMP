struct EString2 {
    unsigned short* m_data;
    void clear(void);
    void assign(unsigned short* str);
    EString2& operator=(unsigned short* str);
};

EString2& EString2::operator=(unsigned short* str) {
    unsigned short* old = m_data;
    clear();
    assign(old);
    return *this;
}
