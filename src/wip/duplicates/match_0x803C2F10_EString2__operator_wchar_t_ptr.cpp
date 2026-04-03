struct EString2 {
    unsigned short *m_str;
    operator unsigned short *() const;
};
EString2::operator unsigned short *() const { return m_str; }
