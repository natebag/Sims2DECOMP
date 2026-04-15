/* 0x800C1960 Interaction::SetName(BString2 &) (60B) */

class BString2 {
public:
    char m_data[8];
    BString2& operator=(BString2& other);
};

class Interaction {
public:
    char pad[52];
    BString2 m_name;    // +52 (at offset +0x34)
    int m_flags;        // +60 (at offset +0x3C)

    void SetName(BString2& name);
};

void Interaction::SetName(BString2& name) {
    m_name = name;
    m_flags |= 0x80;
}
