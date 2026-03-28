// 0x800CDD38 (8 bytes) — li 3, 0; blr
// NeighborhoodImpl::GetHouseNumberForLevel(int)

class NeighborhoodImpl {
public:
    void GetHouseNumberForLevel(int);
};

__attribute__((naked))
void NeighborhoodImpl::GetHouseNumberForLevel(int) {
    asm volatile(
        "li 3, 0\n"
        "blr\n"
    );
}
