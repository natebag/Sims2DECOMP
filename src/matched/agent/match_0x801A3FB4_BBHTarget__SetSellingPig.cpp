// 0x801A3FB4 BBHTarget::SetSellingPig(bool) (100B)

class UIReflow {
public:
    char data[24];
    UIReflow();
    ~UIReflow();
    void ResetVisibility(char* name, bool b, int p3);
};

extern char g_str_BBH_pig[16];

class BBHTarget {
public:
    char pad[0x9C];
    int m_9C;
    void SetSellingPig(bool b);
};

void BBHTarget::SetSellingPig(bool b) {
    if (b == m_9C) return;
    m_9C = b;
    UIReflow reflow;
    reflow.ResetVisibility(g_str_BBH_pig, b, 0);
}
