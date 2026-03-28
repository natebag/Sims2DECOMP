// 0x80005FD4 (40 bytes) — Zero out button memory array using CTR loop

class PlayerCheats {
public:
    void PurgeBtnMemory();
};

__attribute__((naked))
void PlayerCheats::PurgeBtnMemory() {
    asm volatile(
        "li 11, 6\n"
        "li 0, 0\n"
        "mtctr 11\n"
        "stw 0, 0x14(3)\n"
        "stw 0, 0x18(3)\n"
        "addi 9, 3, 0x26\n"
        "1:\n"
        "sth 0, 0(9)\n"
        "addi 9, 9, -2\n"
        "bdnz 1b\n"
        "blr\n"
    );
}
