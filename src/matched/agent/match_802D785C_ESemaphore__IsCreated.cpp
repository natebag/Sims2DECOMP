/* ESemaphore_IC::IsCreated() at 0x802D785C (24B) */

struct ESemaphore_IC {
    char m_pad[4];
    int m_field;
    int IsCreated();
};

int ESemaphore_IC::IsCreated() {
    if (m_field) return 1;
    return 0;
}
