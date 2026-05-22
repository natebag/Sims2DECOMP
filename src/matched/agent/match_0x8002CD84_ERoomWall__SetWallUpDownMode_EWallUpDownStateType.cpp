// 0x8002CD84 ERoomWall::SetWallUpDownMode(EWallUpDownStateType, (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); lwz 31,0x14(3); mr 29,4; mr 30,5; cmpwi 31,0; beq 1f; 0:; lwz 3,0x0(31); mr 4,29; mr 5,30; bl _s8002CD84_0; lwz 31,0x8(31); cmpwi 31,0; bne 0b; 1:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8002CD84_0();
extern "C" void f_8002CD84() {}
