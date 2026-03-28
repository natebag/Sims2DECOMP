// 0x800BC96C (8 bytes) — lwz 3, 16(3); blr
// HouseStats::GetNumLevels(void)

class HouseStats {
public:
    void GetNumLevels(void);
};

__attribute__((naked))
void HouseStats::GetNumLevels(void) {
    asm volatile(
        "lwz 3, 16(3)\n"
        "blr\n"
    );
}
