// HouseRecon::findHRSelector(int) at 0x800452A4 (68 bytes)
// Linear search through m_selectors array (28B stride) for entry with m_id==id.

struct HRSelector {
    int m_id;
    char pad[24];
};

class HouseRecon {
public:
    int findHRSelector(int);
private:
    char m_pad0[0x8004];
    HRSelector m_selectors[2048];
    int m_count;
};

int HouseRecon::findHRSelector(int id) {
    int count = m_count;
    int i = 0;
    if (i < count) {
        HRSelector* p = m_selectors;
        do {
            if ((p++)->m_id == id) return i;
            ++i;
        } while (i < count);
    }
    return -1;
}
