// 0x800BC974 (8 bytes) — lwz 3, 20(3); blr
// HouseStats::GetLotSize(void)

class HouseStats {
public:
    void GetLotSize(void);
};

__attribute__((naked))
void HouseStats::GetLotSize(void) {
    asm volatile(
        "lwz 3, 20(3)
"
        "blr
"
    );
}
