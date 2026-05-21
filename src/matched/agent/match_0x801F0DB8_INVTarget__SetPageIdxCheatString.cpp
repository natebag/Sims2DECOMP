// 0x801F0DB8 INVTarget::SetPageIdxCheatString(char *, int) (68B)

extern char g_pageIdx_fmt[];
extern "C" int Sprintf(char* dst, char* fmt, ...);

class INVTarget {
public:
    char _pad0[393];
    unsigned char m_field393;
    unsigned char m_field394;

    void SetPageIdxCheatString(char* out, int n);
};

void INVTarget::SetPageIdxCheatString(char* out, int n) {
    Sprintf(out, g_pageIdx_fmt, m_field393 + 1, m_field394 + 1);
}
