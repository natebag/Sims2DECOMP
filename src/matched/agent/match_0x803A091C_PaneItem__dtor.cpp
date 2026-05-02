// 0x803A091C (84B) PaneItem::~PaneItem(void)
// Vtable-at-+0x1c SI deleting-dtor + Deallocate body + Reset() (non-virtual member call).

class PaneItemBase {
public:
    char data[0x1c];
};

class PaneItem : public PaneItemBase {
public:
    virtual ~PaneItem();
    void Deallocate();
    void Reset();
};

PaneItem::~PaneItem() {
    Deallocate();
    Reset();
}
