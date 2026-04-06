// FLAGS: -fno-schedule-insns
// 0x8039BD90 (20 bytes)
// TArray<EString, TArrayDefaultAllocator>::Init(void)

struct TArrayBase {
    void* m_data;   // 0x00
    int m_count;    // 0x04
    int m_capacity; // 0x08
};

void TArrayBase_Init(TArrayBase* t) {
    t->m_count = 0;
    t->m_data = 0;
    t->m_capacity = 0;
}
