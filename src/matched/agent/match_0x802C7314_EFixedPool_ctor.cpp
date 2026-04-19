// 0x802C7314 (20B) EFixedPool::ctor — 8B zero-init POD
// volatile pointer forces mr r9,r3 save + stw order.

class EFixedPool {
public:
    int m_field_0;
    int m_field_4;
    EFixedPool(void);
};

EFixedPool::EFixedPool(void) {
    volatile int* p = (volatile int*)this;
    p[1] = 0;
    p[0] = 0;
}
