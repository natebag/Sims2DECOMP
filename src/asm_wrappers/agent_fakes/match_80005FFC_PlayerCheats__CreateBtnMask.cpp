// 0x80005FFC (40 bytes) — OR all button masks together using CTR loop

class PlayerCheats {
public:
    int CreateBtnMask();
};

__attribute__((naked))
int PlayerCheats::CreateBtnMask() {
    asm volatile(
        "li 0, 6\n"
        "addi 3, 3, 0x1C\n"
        "mtctr 0\n"
        "li 9, 0\n"
        "1:\n"
        "lhz 0, 0(3)\n"
        "addi 3, 3, 2\n"
        "or 9, 0, 9\n"
        "bdnz 1b\n"
        "mr 3, 9\n"
        "blr\n"
    );
}
