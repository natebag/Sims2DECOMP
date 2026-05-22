// 0x8002FD7C ERoomWall::GetWallAtTile(CTilePt (156 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 29,0x14(1); stw 0,0x24(1); lwz 31,0x14(3); mr 29,4; cmpwi 31,0; beq 2f; 0:; lwz 30,0x0(31); addi 3,1,8; bl _s8002FD7C_0; mr 3,30; addi 4,1,8; bl _s8002FD7C_1; lbz 9,0x0(29); lbz 0,0x8(1); cmpw 9,0; bne 1f; lbz 9,0x1(29); lbz 0,0x9(1); cmpw 9,0; bne 1f; addi 3,1,8; li 4,2; bl _s8002FD7C_2; mr 3,30; b 3f; 1:; lwz 31,0x8(31); addi 3,1,8; li 4,2; bl _s8002FD7C_3; cmpwi 31,0; bne 0b; 2:; li 3,0; 3:; lwz 0,0x24(1); mtspr 8,0; lmw 29,0x14(1); addi 1,1,32"
extern "C" void _s8002FD7C_0();
extern "C" void _s8002FD7C_1();
extern "C" void _s8002FD7C_2();
extern "C" void _s8002FD7C_3();
extern "C" void f_8002FD7C() {}
