/* QuickStringSet::GetID(void) at 0x800A7C08 (24B) */

struct AStringSet {
    void* _pad0;
    void* _pad1;
    short m_id;
};

class QuickStringSet {
public:
    void* _pad0;
    void* m_locInfo;
    AStringSet* m_string;

    short GetID();
};

short QuickStringSet::GetID() {
    if (!m_string) {
        return 0;
    }
    return m_string->m_id;
}
