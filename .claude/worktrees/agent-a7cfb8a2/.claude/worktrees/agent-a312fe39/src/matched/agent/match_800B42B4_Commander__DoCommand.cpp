// 0x800B42B4 (8 bytes) — li 3, 0; blr
// Commander::DoCommand(short, int)

class Commander {
public:
    void DoCommand(short, int);
};

__attribute__((naked))
void Commander::DoCommand(short, int) {
    asm volatile(
        "li 3, 0\n"
        "blr\n"
    );
}
