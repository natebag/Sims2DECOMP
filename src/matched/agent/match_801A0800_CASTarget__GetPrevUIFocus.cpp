class CASTarget {
public:
    char _pad[0xA0];
    int m_prevUIFocus;

    int GetPrevUIFocus();
};

int CASTarget::GetPrevUIFocus() {
    return m_prevUIFocus;
}
