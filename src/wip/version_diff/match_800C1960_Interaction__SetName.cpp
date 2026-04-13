/* Interaction::SetName(BString2 &) - 60 bytes */

struct BString2 {
    int m_data[2];
    BString2 &operator=(BString2 &rhs);
};

struct Interaction {
    char m_pad[0x34];
    BString2 m_name;
    int m_flags;

    void SetName(BString2 &name);
};

void Interaction::SetName(BString2 &name) {
    m_name = name;
    m_flags = m_flags | 0x80;
}
