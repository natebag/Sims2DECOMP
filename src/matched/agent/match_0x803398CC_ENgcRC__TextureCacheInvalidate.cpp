// 0x803398CC (92B) ENgcRC::TextureCacheInvalidate(void)
// BeginCommand(0,0); char* p = NewEntry(1); *p = 66; m_field_20 = 1; --m_field_24;
// stmw/lmw r30 saves `this` across the two bl calls.

class ERC {
public:
    void BeginCommand(int a, int b);
    char* NewEntry(int n);
};

class ENgcRC : public ERC {
public:
    char pad[20 - 4];   // base ERC vtable already takes 4 bytes
    int  m_field_20;    // offset 20
    char m_field_24;    // offset 24
    void TextureCacheInvalidate();
};

void ENgcRC::TextureCacheInvalidate() {
    BeginCommand(0, 0);
    char* p = NewEntry(1);
    *p = 66;
    m_field_20 = 1;
    --m_field_24;
}
