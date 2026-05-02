// 0x801D1994 (116B) PZ1Target::~PZ1Target(void)
// Variant L: non-deleting dtor — vtable@+0x80 + switch-case snapshot of m_8c to one of 3 SDA globals.

extern char vt_PZ1Target[];
extern void* g_pz1Snap26;
extern void* g_pz1Snap30;
extern void* g_pz1Snap39;

void PAZBase_dtor(void* obj);

struct PZ1Target {
    char pad_00_7f[128];
    void* m_vt_at_80;
    char pad_84_8b[8];
    void* m_field_8c;
    char pad_90_bb[44];
    int m_field_bc;
    void dtor();
};

void PZ1Target::dtor() {
    m_vt_at_80 = vt_PZ1Target;
    int sel = m_field_bc;
    switch (sel) {
    case 26: g_pz1Snap26 = m_field_8c; break;
    case 30: g_pz1Snap30 = m_field_8c; break;
    case 39: g_pz1Snap39 = m_field_8c; break;
    }
    PAZBase_dtor(this);
}
