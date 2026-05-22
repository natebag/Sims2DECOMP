// 0x800308A0 ERoomWall::ERoomWall(void) (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lis 9,-32698; mr 30,3; addi 9,9,-20592; stw 9,0x3c(30); bl _s800308A0_0; addi 3,30,3; bl _s800308A0_1; li 0,0; addi 10,30,20; stw 0,0x4(10); lis 9,-32707; lfs f0,0xecc(9); li 11,1; stw 0,0x14(30); mr 3,30; stw 11,0x8(10); stw 0,0x30(30); stfs f0,0x38(30); stw 0,0x2c(30); stfs f0,0x34(30); lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s800308A0_0();
extern "C" void _s800308A0_1();
extern "C" void f_800308A0() {}
