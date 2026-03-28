class Commander {
public:
    Commander *m_next;

    Commander *GetNext(void);
};

Commander *Commander::GetNext(void) {
    return m_next;
}
