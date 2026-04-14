/* QuickStringSet::Count(char) at 0x800A7620 (84B) */

struct AStringSet {
    int* m_data;
};

class QuickStringSet {
public:
    void* _vtable;
    AStringSet* m_locInfo;
    AStringSet* m_string;

    int Count(char loc);
};

int QuickStringSet::Count(char loc) {
    AStringSet* s = m_string;
    if (s != 0) {
        int* data = s->m_data;
        int count = 0;
        if (data != 0) count = data[-1];
        return count;
    }
    AStringSet* ls = m_locInfo;
    if (ls != 0) {
        int* data2 = ls->m_data;
        int count = 0;
        if (data2 != 0) count = data2[-1];
        return count;
    }
    return 0;
}
