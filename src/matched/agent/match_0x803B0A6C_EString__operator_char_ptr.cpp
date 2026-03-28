struct EString {
    char *m_str;
    operator char *() const;
};
EString::operator char *() const { return m_str; }
