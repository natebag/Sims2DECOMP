// 0x801D1510 (52B) PAZTarget::~PAZTarget(void)
// Variant L: non-deleting dtor — vtable@+0x80, snapshot m_field_8c to SDA, parent ~PAZBase.

extern char vt_PAZTarget[];
extern void* g_pazTargetSnapshot;

void PAZBase_dtor(void* obj);

struct PAZTarget {
    char pad_00_7f[128];
    void* m_vt_at_80;
    char pad_84_8b[8];
    void* m_field_8c;
    void dtor();
};

void PAZTarget::dtor() {
    m_vt_at_80 = vt_PAZTarget;
    g_pazTargetSnapshot = m_field_8c;
    PAZBase_dtor(this);
}
