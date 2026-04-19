// 0x801B9434 (20B) INGTarget::IngInfo::ctor — 8B zero-init POD
// volatile pointer forces mr r9,r3 save + stw order.

class IngInfo {
public:
    int m_field_0;
    int m_field_4;
    IngInfo(void);
};

IngInfo::IngInfo(void) {
    volatile int* p = (volatile int*)this;
    p[1] = 0;
    p[0] = 0;
}
