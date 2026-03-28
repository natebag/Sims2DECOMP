// 0x800D18A8 (8 bytes) — lha 3, 132(3); blr
// NeighborhoodImpl::GetHighestLevelCompleted(void)

class NeighborhoodImpl {
public:
    void GetHighestLevelCompleted(void);
};

__attribute__((naked))
void NeighborhoodImpl::GetHighestLevelCompleted(void) {
    asm volatile(
        "lha 3, 132(3)\n"
        "blr\n"
    );
}
