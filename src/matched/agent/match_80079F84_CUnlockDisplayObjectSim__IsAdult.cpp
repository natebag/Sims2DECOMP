// 0x80079F84 (8 bytes) — li 3, 1; blr
// CUnlockDisplayObjectSim::IsAdult(void)

class CUnlockDisplayObjectSim {
public:
    void IsAdult(void);
};

__attribute__((naked))
void CUnlockDisplayObjectSim::IsAdult(void) {
    asm volatile(
        "li 3, 1\n"
        "blr\n"
    );
}
