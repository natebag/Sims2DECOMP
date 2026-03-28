// 0x800D1294 (8 bytes) — lwz 3, 112(3); blr
// NeighborhoodImpl::GetHouseNumber(void)

class NeighborhoodImpl {
public:
    void GetHouseNumber(void);
};

__attribute__((naked))
void NeighborhoodImpl::GetHouseNumber(void) {
    asm volatile(
        "lwz 3, 112(3)
"
        "blr
"
    );
}
