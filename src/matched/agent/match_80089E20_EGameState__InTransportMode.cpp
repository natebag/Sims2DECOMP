// 0x80089E20 (8 bytes) — li 3, 0; blr
// EGameState::InTransportMode(void)

class EGameState {
public:
    void InTransportMode(void);
};

__attribute__((naked))
void EGameState::InTransportMode(void) {
    asm volatile(
        "li 3, 0
"
        "blr
"
    );
}
