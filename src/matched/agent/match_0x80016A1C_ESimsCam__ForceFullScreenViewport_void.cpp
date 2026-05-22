// 0x80016A1C ESimsCam::ForceFullScreenViewport(void) (112 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 30,0x18(1); stw 0,0x24(1); lis 9,-32697; lwz 0,0x5c70(9); cmpwi 0,0; beq 0f; addi 30,3,16; mr 4,30; bl _s80016A1C_0; lis 11,-32707; lis 10,-32707; lfs f0,-7392(11); addi 9,1,8; lfs f13,-7388(10); mr 3,30; stfs f0,0x8(1); mr 4,9; stfs f0,0x4(9); stfs f13,0xc(9); stfs f13,0x8(9); bl _s80016A1C_1; 0:; lwz 0,0x24(1); mtspr 8,0; lmw 30,0x18(1); addi 1,1,32"
extern "C" void _s80016A1C_0();
extern "C" void _s80016A1C_1();
extern "C" void f_80016A1C() {}
