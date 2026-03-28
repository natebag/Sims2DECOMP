// 0x800122B0 (40 bytes) — Bit set/clear on stateFlags based on bool
// cmpwi r4, 1; bne +0x14; lwz r0, 0(r3); ori r0, r0, 1; stw r0, 0(r3); blr
// lwz r0, 0(r3); rlwinm r0, r0, 0, 1, 30; stw r0, 0(r3); blr

class AwarenessManager {
public:
    void SetPlayerControl(bool val);
};

__attribute__((naked))
void AwarenessManager::SetPlayerControl(bool val) {
    asm volatile(
        "cmpwi 4, 1\n"
        "bne 1f\n"
        "lwz 0, 0(3)\n"
        "ori 0, 0, 1\n"
        "stw 0, 0(3)\n"
        "blr\n"
        "1:\n"
        "lwz 0, 0(3)\n"
        "rlwinm 0, 0, 0, 0, 30\n"
        "stw 0, 0(3)\n"
        "blr\n"
    );
}
