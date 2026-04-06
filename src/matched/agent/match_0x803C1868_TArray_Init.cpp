// FLAGS: -fno-schedule-insns
// 0x803C1868 (20 bytes)
// TArray::Init(void)

struct TArrayBase {
    void* m_data;
    int m_count;
    int m_capacity;
};

void TArrayBase_Init(TArrayBase* t) {
    t->m_count = 0;
    t->m_data = 0;
    t->m_capacity = 0;
}
