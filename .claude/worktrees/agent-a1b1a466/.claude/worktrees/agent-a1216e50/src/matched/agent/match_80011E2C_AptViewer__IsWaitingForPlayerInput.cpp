// 0x80011E2C (44 bytes) — Check two fields for waiting state

class AptViewer {
public:
    int IsWaitingForPlayerInput();
};

__attribute__((naked))
int AptViewer::IsWaitingForPlayerInput() {
    asm volatile(
        "lwz 0, 0x350(3)\n"
        "cmpwi 0, 0\n"
        "beq 2f\n"
        "lwz 0, 0x3A4(3)\n"
        "li 3, 0\n"
        "cmpwi 0, 0\n"
        "beqlr\n"
        "li 3, 1\n"
        "blr\n"
        "2:\n"
        "li 3, 0\n"
        "blr\n"
    );
}
