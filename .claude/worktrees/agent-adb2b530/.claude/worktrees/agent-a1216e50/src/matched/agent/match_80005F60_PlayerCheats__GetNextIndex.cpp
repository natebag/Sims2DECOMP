// 0x80005F60 (36 bytes) — Increment index, wrap at 5, return result

class PlayerCheats {
public:
    int GetNextIndex(int& index);
};

__attribute__((naked))
int PlayerCheats::GetNextIndex(int& index) {
    asm volatile(
        "lwz 9, 0(4)\n"
        "addi 9, 9, 1\n"
        "cmpwi 9, 5\n"
        "stw 9, 0(4)\n"
        "ble 1f\n"
        "li 0, 0\n"
        "stw 0, 0(4)\n"
        "1:\n"
        "lwz 3, 0(4)\n"
        "blr\n"
    );
}
