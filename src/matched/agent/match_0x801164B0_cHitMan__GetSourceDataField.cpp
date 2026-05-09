// 0x801164B0 (52B) cHitMan::GetSourceDataField(int, int, int*)
// Forwards to callback stored at this+48 via blrl.

class cHitMan {
public:
    char _pad[48];
    int (*m_callback)(int, int, int*);
    int GetSourceDataField(int a, int b, int* c);
};

int cHitMan::GetSourceDataField(int a, int b, int* c)
{
    return m_callback(a, b, c);
}
