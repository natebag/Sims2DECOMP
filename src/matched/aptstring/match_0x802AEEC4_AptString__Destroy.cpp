// 0x802AEEC4 AptString::Destroy(void) (84B)

class EAStringC {
public:
    int IsEnoughSize(unsigned int n) const;
    void Clear();
};

class AptString {
public:
    char pad[0xC];
    EAStringC m_str;
    void* m_next;
    void Destroy();
};

extern AptString* g_aptStringList;  // SDA r13-26892

void AptString::Destroy() {
    m_next = g_aptStringList;
    g_aptStringList = this;
    if (m_str.IsEnoughSize(33) != 0) {
        m_str.Clear();
    }
}
