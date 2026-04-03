/* QuickStringSet::GetLocString(int) at 0x800A76FC (92B) */
/* r3=hidden_ret, r4=this, r5=idx */

struct StrPtr {
    char* ptr;
};

class QuickStringSet {
public:
    void* _vtable;
    void* m_locInfo;
    void* m_string;
    char* m_default;

    StrPtr GetLocString(int idx);
};

StrPtr QuickStringSet::GetLocString(int idx) {
    int* loc = (int*)m_locInfo;
    StrPtr ret;
    if (loc != 0) {
        if (idx > 0) {
            int* data = (int*)loc[0];
            int count = 0;
            if (data != 0) count = data[-1];
            if (idx <= count) {
                ret.ptr = (char*)data[idx - 1];
                return ret;
            }
        }
    }
    ret.ptr = m_default;
    return ret;
}
