class CASTarget {
public:
    char _pad[0x134C];
    int m_currentSimNumber;

    int GetCurrentSimNumber();
};

int CASTarget::GetCurrentSimNumber() {
    return m_currentSimNumber;
}
