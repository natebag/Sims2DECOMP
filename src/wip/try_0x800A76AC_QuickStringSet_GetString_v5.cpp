// 0x800A76AC QuickStringSet::GetString(int, char) (80B)
// goto shared label forces beq-to-tail pattern + r9=ss, r11=data alloc (not r11=ss, r9=saved_idx)

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
        if (idx > count) goto ret_null;
        return (char*)data[idx - 1];
    }
ret_null:
    return 0;
}
