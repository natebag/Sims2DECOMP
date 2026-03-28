class Commander {
public:
    void *m_next;
    int m_type;

    int GetType(void);
};

int Commander::GetType(void) {
    return m_type;
}
