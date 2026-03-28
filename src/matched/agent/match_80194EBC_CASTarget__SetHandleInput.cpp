class CASTarget {
public:
    char _pad[0x8C];
    int m_handleInput;

    void SetHandleInput(bool value);
};

void CASTarget::SetHandleInput(bool value) {
    m_handleInput = value;
}
