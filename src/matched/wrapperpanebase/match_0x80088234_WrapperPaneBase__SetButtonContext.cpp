// FLAGS: -fno-elide-constructors
int WPB_HashStr(char *);

struct WPB_SBC {
    char _pad[0x38];
    char *m_contextStr;
    int m_contextHash;

    void SetButtonContext(char *str);
};

void WPB_SBC::SetButtonContext(char *str) {
    m_contextStr = str;
    if (str == 0) {
        m_contextHash = 0;
    } else {
        m_contextHash = WPB_HashStr(str);
    }
}
