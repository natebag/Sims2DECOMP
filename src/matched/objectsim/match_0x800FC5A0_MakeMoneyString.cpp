// 0x800FC5A0 MakeMoneyString(StringBuffer2&, int) (100B)

typedef unsigned short u16;

class StringBuffer2 {
public:
    char data[8];
    StringBuffer2(u16* buf, unsigned int cap);
    u16* c_str() const;
    StringBuffer2& copy(u16* src);
};

template <int N>
class StackString2 {
public:
    StringBuffer2 m_buf;
    u16 m_chars[N];
};

extern void GetMoneyString(int amount, StackString2<256>& s, bool flag);

struct StackString256 {
    StringBuffer2 m_buf;
    u16 m_chars[256];
    StackString256() : m_buf(m_chars, 256) {}
};

void MakeMoneyString(StringBuffer2& out, int amount) {
    StackString256 ss;
    GetMoneyString(amount, *(StackString2<256>*)&ss, false);
    out.copy(ss.m_buf.c_str());
}
