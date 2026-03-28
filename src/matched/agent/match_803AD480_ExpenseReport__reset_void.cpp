// 0x803AD480 (32 bytes)
struct ExpenseReport {
    void reset(void);
    unsigned int m_data[8];
};

void ExpenseReport::reset(void) {
    unsigned int* p = (unsigned int*)((char*)this + 0x1c);
    for (int i = 0; i < 8; i++) {
        *p = 0;
        p--;
    }
}
