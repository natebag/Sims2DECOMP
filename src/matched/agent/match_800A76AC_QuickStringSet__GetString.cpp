/* QuickStringSet::GetString(int, char) at 0x800A76AC (80B) */

class QuickStringSet {
public:
    void* _vtable;
    void* m_locInfo;
    void* m_string;

    char* GetString(int idx, char loc);
};

char* QuickStringSet::GetString(int idx, char loc) {
    int* ss = (int*)m_string;
    if (ss == 0) return 0;
    if (idx <= 0) return 0;
    int* data = (int*)(ss[0]);
    int count = 0;
    if (data != 0) count = data[-1];
    if (idx > count) return 0;
    return (char*)data[idx - 1];
}
