// 0x8016A8F8 (88B) CasSimPartsS2C::~CasSimPartsS2C(void)
// Variant L: SI deleting-dtor, conditional EResource::DelRef + clear m0/m4.

void EResource_DelRef(void* obj);
void __builtin_delete(void* p);

struct CasSimPartsS2C {
    void* m_field_0;
    int m_field_4;
    void dtor(int flag);
};

void CasSimPartsS2C::dtor(int flag) {
    void* p = m_field_0;
    m_field_4 = 0;
    if (p != 0) {
        EResource_DelRef(p);
        m_field_0 = 0;
    }
    if (flag & 1) {
        __builtin_delete(this);
    }
}
