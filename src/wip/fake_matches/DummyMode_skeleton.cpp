// 0x80099834 DummyMode::DummyMode (48b)
// Pattern: Vtable + field init with constants

extern int DummyMode_vtable[];

struct DummyMode {
    int* m_vt;      // offset 0
    int m_field4;   // offset 4
    int m_field8;   // offset 8
    DummyMode();
};

DummyMode::DummyMode() {
    DummyMode* p = this;
    p->m_vt = (int*)DummyMode_vtable;
    p->m_field4 = 2;
    p->m_field8 = 0;
}
