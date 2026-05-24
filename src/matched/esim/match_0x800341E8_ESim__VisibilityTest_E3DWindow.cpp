// 0x800341E8 ESim::VisibilityTest(E3DWindow (228 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-136(1); mfspr 0,8; stmw 27,0x74(1); stw 0,0x8c(1); mr 31,3; mr 27,4; bl _s800341E8_0; cmpwi 3,0; beq 0f; li 3,0; b 2f; 0:; addi 28,31,820; lwz 0,0x10(28); cmpwi 0,0; bne 1f; mr 3,27; addi 4,31,256; bl _s800341E8_1; b 2f; 1:; lis 9,-32707; lwz 8,0x0(31); lfs f0,0x11f8(9); addi 10,1,20; addi 30,1,8; addi 29,1,48; stfs f0,0x20(1); mr 4,29; stfs f0,0x28(1); stfs f0,0x24(1); lwz 0,0x20(1); lwz 9,0x24(1); lwz 11,0x28(1); stw 0,0x14(1); stw 11,0x8(10); stw 9,0x4(10); lwz 0,0x14(1); stw 0,0x8(1); stw 9,0x4(30); stw 11,0x8(30); lha 3,0x110(8); lwz 0,0x114(8); add 3,31,3; mtspr 8,0; blrl; mr 3,28; mr 4,29; mr 5,30; li 6,0; bl _s800341E8_2; mr 3,27; mr 4,30; bl _s800341E8_3; 2:; lwz 0,0x8c(1); mtspr 8,0; lmw 27,0x74(1); addi 1,1,136"

extern "C" void _s800341E8_0();
extern "C" void _s800341E8_1();
extern "C" void _s800341E8_2();
extern "C" void _s800341E8_3();

struct ESim {
    void VisibilityTest_E3DWindow();
};

void ESim::VisibilityTest_E3DWindow() {
}
