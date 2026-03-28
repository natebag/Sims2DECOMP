class E2ETarget {
public:
    char _pad[0xA8];
    unsigned int m_index;
    unsigned int m_maxIndex;

    void UpdateText();
    void OnUpKeyPressed(char *, char *);
};

void E2ETarget::OnUpKeyPressed(char *, char *) {
    m_index = (m_index + 1) % m_maxIndex;
    UpdateText();
}
