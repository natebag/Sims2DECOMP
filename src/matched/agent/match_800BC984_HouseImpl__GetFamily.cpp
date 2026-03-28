// 0x800BC984 (8 bytes) — lwz 3, 20(3); blr
// HouseImpl::GetFamily(void)

class HouseImpl {
public:
    void GetFamily(void);
};

__attribute__((naked))
void HouseImpl::GetFamily(void) {
    asm volatile(
        "lwz 3, 20(3)
"
        "blr
"
    );
}
