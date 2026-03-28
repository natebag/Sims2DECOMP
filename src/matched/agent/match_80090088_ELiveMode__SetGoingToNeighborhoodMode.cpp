// 0x80090088 (8 bytes) — stw 4, 36(3); blr
// ELiveMode::SetGoingToNeighborhoodMode(bool)

class ELiveMode {
public:
    void SetGoingToNeighborhoodMode(bool);
};

__attribute__((naked))
void ELiveMode::SetGoingToNeighborhoodMode(bool) {
    asm volatile(
        "stw 4, 36(3)
"
        "blr
"
    );
}
