// 0x8010FF70 (92B) ObjFnTableQuickData::~ObjFnTableQuickData(void)
// Variant L: dual-vtable transition + delete inner buffer + conditional delete this.

extern char vt_ObjFnTableQuickData_a[];
extern char vt_ObjFnTableQuickData_b[];

void __builtin_delete(void* p);

struct ObjFnTableQuickData {
    void* m_vt_at_0;
    char pad_4_f[12];
    void* m_field_10;
    void dtor(int flag);
};

void ObjFnTableQuickData::dtor(int flag) {
    m_vt_at_0 = vt_ObjFnTableQuickData_a;
    __builtin_delete(m_field_10);
    m_vt_at_0 = vt_ObjFnTableQuickData_b;
    if (flag & 1) {
        __builtin_delete(this);
    }
}
