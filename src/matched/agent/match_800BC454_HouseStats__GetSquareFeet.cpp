// 0x800BC454 (8 bytes) — lwz 3, 0(3); blr
// HouseStats::GetSquareFeet(void)

class HouseStats {
public:
    void GetSquareFeet(void);
};

__attribute__((naked))
void HouseStats::GetSquareFeet(void) {
    asm volatile(
        "lwz 3, 0(3)
"
        "blr
"
    );
}
