// 0x800210E4 (64 bytes) — Constructor: initializes fields with constants
// ECheatLookup::ECheatLookup(void)

class ECheatLookup {
public:
    ECheatLookup();
};

__attribute__((naked))
ECheatLookup::ECheatLookup() {
    asm volatile(
        "lis 11, -32707\n"
        "mr 9, 3\n"
        "li 0, 0\n"
        "addi 11, 11, -6164\n"
        "li 10, -1\n"
        "li 8, 0\n"
        "li 7, 2\n"
        "stw 10, 4(9)\n"
        "stb 8, 8(9)\n"
        "stw 7, 76(9)\n"
        "stw 0, 92(9)\n"
        "stw 11, 72(9)\n"
        "stw 0, 80(9)\n"
        "stw 0, 84(9)\n"
        "stw 0, 88(9)\n"
        "blr\n"
    );
}
