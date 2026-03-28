// 0x80048510 (8 bytes) — lhz 3, 130(3); blr
// EIFloor::GetNumRoomID(void)

class EIFloor {
public:
    void GetNumRoomID(void);
};

__attribute__((naked))
void EIFloor::GetNumRoomID(void) {
    asm volatile(
        "lhz 3, 130(3)
"
        "blr
"
    );
}
