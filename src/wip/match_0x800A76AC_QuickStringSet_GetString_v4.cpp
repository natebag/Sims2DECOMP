// 0x800A76AC QuickStringSet::GetString(int) (80 bytes)
// DOL: lwz r9(m_data), check m_data, check index, load arr(r11),
//      li r0,0 (count init), check arr, load count(r0), compare, return arr[idx-1]

struct QuickStringSet {
    char m_pad[8];
    void** m_data;

    char* GetString(int index);
};

char* QuickStringSet::GetString(int index) {
    void** data = m_data;
    if (!data) return 0;
    if (index <= 0) return 0;
    char** arr = (char**)*data;
    int count = 0;
    if (!arr) return 0;
    count = ((int*)arr)[-1];
    if (index > count) return 0;
    return arr[index - 1];
}
