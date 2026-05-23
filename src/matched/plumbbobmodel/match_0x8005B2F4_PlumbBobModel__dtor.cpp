// 0x8005B2F4 (108B) PlumbBobModel::~PlumbBobModel(void)
// Variant L: dual conditional EResource::DelRef on m_28/m_2c + __builtin_delete branch.

void EResource_DelRef(void* obj);
void __builtin_delete(void* p);

struct PlumbBobModel {
    char pad_00_27[40];
    void* m_field_28;
    void* m_field_2c;
    void dtor(int flag);
};

void PlumbBobModel::dtor(int flag) {
    if (m_field_28 != 0) {
        EResource_DelRef(m_field_28);
        m_field_28 = 0;
    }
    if (m_field_2c != 0) {
        EResource_DelRef(m_field_2c);
        m_field_2c = 0;
    }
    if (flag & 1) {
        __builtin_delete(this);
    }
}
