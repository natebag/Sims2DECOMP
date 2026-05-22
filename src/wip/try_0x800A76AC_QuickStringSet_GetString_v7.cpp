// FLAGS: -fno-schedule-insns
// 0x800A76AC QuickStringSet::GetString(int, char) (80B)
// register hint on ss to get r9 for first scratch instead of r11

struct QuickStringSet {
    void* _vtable;
    void* m_locInfo;
    void** m_string;
    char* GetString(int idx, char loc);
};

char* QuickStringSet::GetString(int idx, char loc) {
    register int** ss = (int**)m_string;
    if (!ss) goto ret_null;
    if (idx <= 0) goto ret_null;
    {
        register int* data = (int*)ss[0];
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
