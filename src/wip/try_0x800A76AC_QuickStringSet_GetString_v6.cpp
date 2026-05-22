// FLAGS: -fno-schedule-insns
// 0x800A76AC QuickStringSet::GetString(int, char) (80B)
// DOL: null checks goto shared tail, idx<=count goto forward access, inline return for idx>count

struct QuickStringSet {
    void* _vtable;
    void* m_locInfo;
    void** m_string;
    char* GetString(int idx, char loc);
};

char* QuickStringSet::GetString(int idx, char loc) {
    int** ss = (int**)m_string;
    if (!ss) goto ret_null;
    if (idx <= 0) goto ret_null;
    {
        int* data = (int*)ss[0];
        int count = 0;
        if (data) count = data[-1];
        if (idx <= count) goto access;
        return 0;
    access:
        return (char*)data[idx - 1];
    }
ret_null:
    return 0;
}
