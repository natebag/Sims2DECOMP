// 0x8018155C UIButtonImages::AddRefAll(void) (84B)

class EResourceManager {
public:
    void AddRefAsync(unsigned int id);
};

extern char _shaderman[16];  // 0x804BBBDC — char[16] forces HA/LO (Tech #17)

class UIButtonImages {
public:
    unsigned int m_ids[14];   // 0..56
    char pad_38[112];
    int m_refed;              // 168
    void AddRefAll();
};

void UIButtonImages::AddRefAll() {
    unsigned int* p = m_ids;
    unsigned int* end = m_ids + 13;
    do {
        unsigned int id = *p;
        p++;
        ((EResourceManager*)_shaderman)->AddRefAsync(id);
    } while ((int)p <= (int)end);
    m_refed = 1;
}
