// 0x8002A408 EIWallPart::VisibilityTest(E3DWindow (152 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; lis 9,-32707; mr 3,4; lfs f12,0x380(31); lfs f13,0x284(3); lfs f0,0x280(3); lfs f11,0x37c(31); fmuls f13,f13,f12; lfs f10,0x384(31); fmadds f0,f0,f11,f13; lfs f12,0xd64(9); fsubs f0,f0,f10; fcmpu 0,f0,f12; bge 0f; mr 3,31; li 4,0; bl _s8002A408_0; li 3,1; b 2f; 0:; addi 4,31,60; bl _s8002A408_1; mr 30,3; li 4,1; cmpwi 30,1; bne 1f; li 4,0; 1:; mr 3,31; bl _s8002A408_2; mr 3,30; 2:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"

extern "C" void _s8002A408_0();
extern "C" void _s8002A408_1();
extern "C" void _s8002A408_2();

struct EIWallPart {
    void VisibilityTest_E3DWindow();
};

void EIWallPart::VisibilityTest_E3DWindow() {
}
