// 0x800A7B70 (128B) QuickStringSet::LoadLocRes(iResFile*, short)
// Null-guarded resource lookup via FindRes template.

struct WStringSet;
struct iResFile {
    char pad[8];
    void* m_data;
};

template<typename T>
extern T* FindRes(T* begin, T* end, int id);

struct QuickStringSet {
    char pad[4];
    WStringSet* m_set;
    int m_count;
    
    int LoadLocRes(iResFile* file, short id);
};

int QuickStringSet::LoadLocRes(iResFile* file, short id) {
    m_set = 0;
    m_count = 0;
    if (file && file->m_data) {
        WStringSet* sets = (WStringSet*)((char*)file->m_data + 20);
        if (sets) {
            int count = ((int*)sets)[-1];
            m_set = FindRes(sets, (WStringSet*)((char*)sets + count * 12), id);
        }
    }
    return m_set ? 0 : -1;
}
