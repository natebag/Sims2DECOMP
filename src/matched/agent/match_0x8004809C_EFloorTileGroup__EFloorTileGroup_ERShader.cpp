// 0x8004809C EFloorTileGroup::EFloorTileGroup(ERShader (72 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; mr 3,4; stw 5,0x4(30); stw 6,0xc(30); stw 7,0x8(30); stw 8,0x0(30); stw 4,0x10(30); bl _s8004809C_0; mr 3,30; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8004809C_0();
extern "C" void f_8004809C() {}
