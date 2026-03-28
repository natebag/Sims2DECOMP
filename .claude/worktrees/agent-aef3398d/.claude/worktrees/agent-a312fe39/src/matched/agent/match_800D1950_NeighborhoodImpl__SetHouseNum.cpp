// 0x800D1950 (8 bytes) — stw 4, 112(3); blr
// NeighborhoodImpl::SetHouseNum(int)

class NeighborhoodImpl {
public:
    void SetHouseNum(int);
};

__attribute__((naked))
void NeighborhoodImpl::SetHouseNum(int) {
    asm volatile(
        "stw 4, 112(3)\n"
        "blr\n"
    );
}
