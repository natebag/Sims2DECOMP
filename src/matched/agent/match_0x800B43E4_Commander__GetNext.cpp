/* Commander::GetNext(void) at 0x800B43E4 (8B) */

struct Commander {
    Commander* m_next;

    Commander* GetNext(void);
};

Commander* Commander::GetNext(void) {
    return m_next;
}
