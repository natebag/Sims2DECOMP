// 0x800877C4 IconItem::~IconItem (84B)
// dtor: vtable@+28; bl PaneItem::Startup() [4B helper]; this->PaneItem::Reset(); delete check.

extern int VT_IconItem[];

struct PaneItem {
    void Startup();  // 4B function called for some setup
    void Reset();
};

struct IconItem : public PaneItem {
    char pad[28-4];  // PaneItem is 4 bytes? plus pad to 28
    int* m_vtable;
    ~IconItem();
};

IconItem::~IconItem() {
    m_vtable = VT_IconItem;
    Startup();
    Reset();
}
