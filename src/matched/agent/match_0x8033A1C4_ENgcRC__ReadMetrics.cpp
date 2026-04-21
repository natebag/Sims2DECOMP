// 0x8033A1C4 (92B) ENgcRC::ReadMetrics(void)
// Twin of TextureCacheInvalidate with cmd=72 instead of 66.

class ERC {
public:
    void BeginCommand(int a, int b);
    char* NewEntry(int n);
};

class ENgcRC : public ERC {
public:
    char pad[20 - 4];
    int  m_field_20;
    char m_field_24;
    void ReadMetrics();
};

void ENgcRC::ReadMetrics() {
    BeginCommand(0, 0);
    char* p = NewEntry(1);
    *p = 72;
    m_field_20 = 1;
    --m_field_24;
}
