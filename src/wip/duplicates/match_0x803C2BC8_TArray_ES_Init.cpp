// FLAGS: -fno-schedule-insns
/* TArray<EString2>::Init() @ 0x803C2BC8 (20 bytes) */

struct TArrayES_Init {
    void *m_data;
    int m_count;
    int m_alloc;
    void Init();
};

void TArrayES_Init::Init() {
    m_count = 0;
    m_data = 0;
    m_alloc = 0;
}
