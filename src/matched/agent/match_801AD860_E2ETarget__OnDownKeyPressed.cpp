class E2ETarget {
public:
    char _pad[0xA8];
    int m_index;
    int m_maxIndex;

    void UpdateText();
    void OnDownKeyPressed(char *, char *);
};

void E2ETarget::OnDownKeyPressed(char *, char *) {
    m_index--;
    if (m_index < 0) {
        m_index = m_maxIndex - 1;
    }
    UpdateText();
}
