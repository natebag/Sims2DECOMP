// 0x800BC964 (8 bytes) — lwz 3, 12(3); blr
// HouseStats::GetNumBathrooms(void)

class HouseStats {
public:
    void GetNumBathrooms(void);
};

__attribute__((naked))
void HouseStats::GetNumBathrooms(void) {
    asm volatile(
        "lwz 3, 12(3)\n"
        "blr\n"
    );
}
