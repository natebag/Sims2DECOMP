// 0x802AC428 AptString::DeleteThis(void) (84B)

class EAStringC {
public:
    int IsEnoughSize(unsigned int n) const;
    void Clear();
};

class AptString {
public:
    char pad[0xC];
    EAStringC m_str;        // 0x0C
    void* m_next;           // assumes m_str is 4 bytes; m_next at 0x10
    void DeleteThis();
};

extern AptString* g_aptStringList;  // SDA r13-26892

void AptString::DeleteThis() {
    m_next = g_aptStringList;
    g_aptStringList = this;
    if (m_str.IsEnoughSize(33) != 0) {
        m_str.Clear();
    }
}
