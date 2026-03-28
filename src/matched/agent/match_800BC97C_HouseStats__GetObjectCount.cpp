// 0x800BC97C (8 bytes) — lwz 3, 36(3); blr
// HouseStats::GetObjectCount(void)

class HouseStats {
public:
    void GetObjectCount(void);
};

__attribute__((naked))
void HouseStats::GetObjectCount(void) {
    asm volatile(
        "lwz 3, 36(3)
"
        "blr
"
    );
}
