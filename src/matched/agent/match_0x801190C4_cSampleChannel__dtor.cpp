// 0x801190C4 (76B) cSampleChannel::~cSampleChannel(void)
// Variant L: SI deleting-dtor, Shutdown(flag-passthrough) + clear m0/m4 + __builtin_delete branch.

void cSampleChannel_Shutdown(void* obj, int flag);
void __builtin_delete(void* p);

struct cSampleChannel {
    int m_field_0;
    int m_field_4;
    void dtor(int flag);
};

void cSampleChannel::dtor(int flag) {
    cSampleChannel_Shutdown(this, flag);
    m_field_0 = 0;
    m_field_4 = 0;
    if (flag & 1) {
        __builtin_delete(this);
    }
}
