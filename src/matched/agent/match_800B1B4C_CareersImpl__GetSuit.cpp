// 0x800B1B4C (8 bytes) — lwz 3, 104(4); blr
// CareersImpl::GetSuit(Job &, bool)

class CareersImpl {
public:
    void GetSuit(Job &, bool);
};

__attribute__((naked))
void CareersImpl::GetSuit(Job &, bool) {
    asm volatile(
        "lwz 3, 104(4)
"
        "blr
"
    );
}
