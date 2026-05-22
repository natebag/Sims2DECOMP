// 0x801A3E30 BBHTarget::SetCurrentPrice(int) (100B)

class UIReflow {
public:
    char data[24];
    UIReflow();
    ~UIReflow();
    void ResetFontSizeOverride(char* name, unsigned int sz, int p3);
};

extern char g_str_BBH_price[16];

class BBHTarget {
public:
    char pad[0x84];
    int m_84;
    char pad88[0x10];
    int m_98;
    void SetCurrentPrice(int price);
};

void BBHTarget::SetCurrentPrice(int price) {
    if (m_84 == 0) return;
    if (m_98 == price) return;
    m_98 = price;
    UIReflow reflow;
    reflow.ResetFontSizeOverride(g_str_BBH_price, 12, 0);
}
