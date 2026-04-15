// 0x80084A8C WrapperPaneBase::Startup(void) (40B)
struct PaneItem;

struct WrapperPaneBase {
    void* m_vt;
    unsigned int m_flags;
    PaneItem** m_items;
    PaneItem** m_itemsEnd;
    char pad[48];
    int m_field64;
    int m_field68;
    int m_field72;
    int m_field76;
    int m_field80;
    int m_field84;
    int m_field88;
    void Startup(void);
};

void WrapperPaneBase::Startup() {
    int* ptr = (int*)((char*)this + 88);
    int count = 7;
    int zero = 0;
    m_itemsEnd = m_items;
    do {
        *ptr = zero;
        ptr--;
    } while (--count);
}
