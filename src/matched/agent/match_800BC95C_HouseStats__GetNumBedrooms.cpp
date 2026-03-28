// 0x800BC95C (8 bytes) — lwz 3, 8(3); blr
// HouseStats::GetNumBedrooms(void)

class HouseStats {
public:
    void GetNumBedrooms(void);
};

__attribute__((naked))
void HouseStats::GetNumBedrooms(void) {
    asm volatile(
        "lwz 3, 8(3)\n"
        "blr\n"
    );
}
