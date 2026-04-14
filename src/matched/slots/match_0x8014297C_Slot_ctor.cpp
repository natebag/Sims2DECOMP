// 0x8014297C Slot::Slot(SlotDescriptor*) (20b)

struct SlotDescriptor;
extern int Slot_vtable[];

struct Slot {
    int* m_vt;
    Slot(SlotDescriptor* p2);
};

Slot::Slot(SlotDescriptor* p2) {
    *(int**)this = Slot_vtable;
}
