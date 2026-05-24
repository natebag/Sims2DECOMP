// 0x802EFF38 EAnimController::VisibilityTest(EMat4 (148 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stmw 30,0x30(1); stw 0,0x3c(1); lwz 31,-26704(13); cmpwi 31,0; bne 0f; li 3,0; b 1f; 0:; lis 9,-32702; addi 10,1,20; lfs f0,-4312(9); addi 30,1,8; mr 5,30; li 6,0; stfs f0,0x20(1); stfs f0,0x28(1); stfs f0,0x24(1); lwz 0,0x20(1); lwz 9,0x24(1); lwz 11,0x28(1); stw 0,0x14(1); stw 11,0x8(10); stw 9,0x4(10); lwz 0,0x14(1); stw 0,0x8(1); stw 9,0x4(30); stw 11,0x8(30); bl _s802EFF38_0; mr 3,31; mr 4,30; bl _s802EFF38_1; 1:; lwz 0,0x3c(1); mtspr 8,0; lmw 30,0x30(1); addi 1,1,56"

extern "C" void _s802EFF38_0();
extern "C" void _s802EFF38_1();

struct EAnimController {
    void VisibilityTest();
};

void EAnimController::VisibilityTest() {
}
