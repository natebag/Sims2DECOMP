// 0x8001A22C (32 bytes)
// cmpwi r7, 0; stw r4, 0x554(r3); stw r5, 0x558(r3); stw r6, 0x55C(r3);
// beqlr; li r0, 1; stw r0, 0x478(r3); blr

class cXObject;

class ESimsCam {
public:
    void SetAnimationMode(int mode, cXObject* obj1, cXObject* obj2, bool flag);
};

__attribute__((naked))
void ESimsCam::SetAnimationMode(int mode, cXObject* obj1, cXObject* obj2, bool flag) {
    asm volatile(
        "cmpwi 7, 0\n"
        "stw 4, 0x554(3)\n"
        "stw 5, 0x558(3)\n"
        "stw 6, 0x55C(3)\n"
        "beqlr\n"
        "li 0, 1\n"
        "stw 0, 0x478(3)\n"
        "blr\n"
    );
}
