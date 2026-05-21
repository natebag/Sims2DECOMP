// 0x800A7B70 QuickStringSet::LoadLocRes(iResFile *, short) (128B)

class WStringSet;

class iResFile {
public:
    char _pad[8];
    void* m_field8;
};

extern int FindRes(WStringSet* begin, WStringSet* end, int id);

class QuickStringSet {
public:
    char _pad0[4];
    int m_field4;
    int m_field8;

    int LoadLocRes(iResFile* f, short id);
};

int QuickStringSet::LoadLocRes(iResFile* f, short id) {
    if (f != 0) {
        *(volatile int*)&m_field8 = 0;
        *(volatile int*)&m_field4 = 0;
        WStringSet* set = (WStringSet*)f->m_field8;
        if (set != 0) {
            char* arr = *(char**)((char*)set + 20);
            int count = 0;
            if (arr != 0) count = *(int*)(arr - 4);
            m_field4 = FindRes((WStringSet*)arr, (WStringSet*)(arr + count * 12), id);
        }
    }
    int r = 0;
    if (m_field4 == 0) r = -1;
    return r;
}
