// 0x800A76AC QuickStringSet::GetString(int) (80 bytes)

struct QuickStringSet {
    char m_pad[8];    // 0x00-0x07
    void** m_data;    // 0x08 — ptr to array of ptrs

    char* GetString(int index);
};

char* QuickStringSet::GetString(int index) {
    void** data = m_data;
    if (!data) return 0;
    if (index <= 0) return 0;
    char** arr = (char**)*data;
    char* result = 0;
    if (!arr) return result;
    int count = ((int*)arr)[-1];
    if (index > count) return 0;
    result = arr[index - 1];
    return result;
}
