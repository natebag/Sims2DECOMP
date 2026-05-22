// 0x8002C48C EFenceWall::EFenceWall(TileWallsSegment (192 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 26,0x8(1); stw 0,0x24(1); lis 9,-32698; mr 30,3; addi 9,9,-20592; mr 28,4; mr 27,5; mr 26,6; stw 9,0x3c(30); bl _s8002C48C_0; addi 29,30,20; addi 3,30,3; bl _s8002C48C_1; li 0,0; li 11,1; stw 0,0x4(29); lis 10,-32707; stw 0,0x14(30); lis 9,-32698; stw 11,0x8(29); addi 9,9,-20648; stw 0,0x30(30); stw 0,0x2c(30); lfs f0,0xdd8(10); stw 9,0x3c(30); stfs f0,0x38(30); stfs f0,0x34(30); bl _s8002C48C_2; li 7,0; li 4,952; li 5,16; li 6,0; bl _s8002C48C_3; mr 4,28; mr 5,27; mr 6,26; bl _s8002C48C_4; mr 4,3; mr 3,29; bl _s8002C48C_5; mr 3,30; lwz 0,0x24(1); mtspr 8,0; lmw 26,0x8(1); addi 1,1,32"
extern "C" void _s8002C48C_0();
extern "C" void _s8002C48C_1();
extern "C" void _s8002C48C_2();
extern "C" void _s8002C48C_3();
extern "C" void _s8002C48C_4();
extern "C" void _s8002C48C_5();
extern "C" void f_8002C48C() {}
