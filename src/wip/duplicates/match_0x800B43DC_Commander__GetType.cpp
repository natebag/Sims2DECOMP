/* Commander::GetType(void) at 0x800B43DC (8B) */

struct Commander {
    void* m_next;
    int m_type;

    int GetType(void);
};

int Commander::GetType(void) {
    return m_type;
}
