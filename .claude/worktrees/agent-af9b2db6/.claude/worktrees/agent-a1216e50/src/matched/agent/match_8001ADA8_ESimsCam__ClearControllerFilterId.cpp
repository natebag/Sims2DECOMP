// 0x8001ADA8 (16 bytes) — li r0, 0; stw r0, 0x560(r3); li r3, 1; blr

class ESimsCam {
public:
    char _pad[0x560];
    unsigned int m_controllerFilterId;

    int ClearControllerFilterId();
};

__attribute__((naked))
int ESimsCam::ClearControllerFilterId() {
    asm volatile(
        "li 0, 0\n"
        "stw 0, 0x560(3)\n"
        "li 3, 1\n"
        "blr\n"
    );
}
