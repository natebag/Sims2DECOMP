// 0x80012250 (8 bytes) — stw 3, -32696(13); blr
// AwarenessManager::SetIsRaining(bool)

class AwarenessManager {
public:
    void SetIsRaining(bool);
};

__attribute__((naked))
void AwarenessManager::SetIsRaining(bool) {
    asm volatile(
        "stw 3, -32696(13)
"
        "blr
"
    );
}
