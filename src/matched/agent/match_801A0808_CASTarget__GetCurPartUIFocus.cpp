class CASTarget {
public:
    char _pad[0xA4];
    int m_curPartUIFocus;

    int GetCurPartUIFocus();
};

int CASTarget::GetCurPartUIFocus() {
    return m_curPartUIFocus;
}
