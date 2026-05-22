// FLAGS: -fno-schedule-insns
// 0x800A76AC QuickStringSet::GetString(int) (80 bytes)

struct QuickStringSet {
    char m_pad[8];    // 0x00-0x07
    void** m_data;    // 0x08

    char* GetString(int index);
};

char* QuickStringSet::GetString(int index) {
    void** data = m_data;
    if (!data) return 0;
    if (index <= 0) return 0;
    char** arr = (char**)*data;
    if (!arr) return 0;
    int count = ((int*)arr)[-1];
    if (index > count) return 0;
    return arr[index - 1];
}
