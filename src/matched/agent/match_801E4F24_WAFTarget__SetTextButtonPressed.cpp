class WAFTarget {
public:
    char pad[0x9C];
    int m_textButtonPressed;
    void SetTextButtonPressed(bool val);
};

void WAFTarget::SetTextButtonPressed(bool val) {
    m_textButtonPressed = val;
}
