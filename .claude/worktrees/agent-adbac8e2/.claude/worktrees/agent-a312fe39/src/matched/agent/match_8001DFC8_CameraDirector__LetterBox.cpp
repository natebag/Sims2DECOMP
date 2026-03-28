// 0x8001DFC8 (24 bytes)
// lwz r0, 0x240(r3); xori r0, r0, 1; andi. r9, r0, 1; beqlr; stw r4, 0x234(r3); blr

class CameraDirector {
public:
    void LetterBox(bool enable);
};

__attribute__((naked))
void CameraDirector::LetterBox(bool enable) {
    asm volatile(
        "lwz 0, 0x240(3)\n"
        "xori 0, 0, 1\n"
        "andi. 9, 0, 1\n"
        "beqlr\n"
        "stw 4, 0x234(3)\n"
        "blr\n"
    );
}
