// 0x80011E1C (16 bytes) — lwz r0, 0x3A4(r3); stw r4, 0x3A4(r3); mr r3, r0; blr

class AptViewer {
public:
    int AllowControllerReading(bool allow);
};

__attribute__((naked))
int AptViewer::AllowControllerReading(bool allow) {
    asm volatile(
        "lwz 0, 0x3A4(3)\n"
        "stw 4, 0x3A4(3)\n"
        "mr 3, 0\n"
        "blr\n"
    );
}
