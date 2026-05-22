// 0x800CCB84 NeighborhoodImpl::~NeighborhoodImpl(void) (296 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); lis 9,-32698; mr 30,3; addi 9,9,1216; addi 11,30,92; stw 9,0x0(30); mr 28,4; lwz 31,0x5c(30); lwz 0,0x4(11); cmpw 31,0; beq 1f; mr 29,11; 0:; lwz 3,0x0(31); addi 31,31,4; bl _s800CCB84_0; lwz 0,0x4(29); cmpw 31,0; bne 0b; 1:; lwz 9,0x5c(30); addi 0,30,92; mr 29,0; addi 31,30,116; mr 3,31; stw 9,0x4(29); bl _s800CCB84_1; lwz 3,0x74(30); cmpwi 3,0; beq 3f; lwz 0,0xc(31); subf 0,3,0; rlwinm 4,0,0,0,29; cmplwi 4,128; ble 2f; bl _s800CCB84_2; b 3f; 2:; bl _s800CCB84_3; 3:; lwz 3,0x5c(30); cmpwi 3,0; beq 5f; lwz 0,0xc(29); subf 0,3,0; rlwinm 4,0,0,0,29; cmplwi 4,128; ble 4f; bl _s800CCB84_4; b 5f; 4:; bl _s800CCB84_5; 5:; lwz 3,0x4c(30); addi 9,30,76; cmpwi 3,0; beq 7f; lwz 0,0xc(9); subf 0,3,0; rlwinm 4,0,0,0,29; cmplwi 4,128; ble 6f; bl _s800CCB84_6; b 7f; 6:; bl _s800CCB84_7; 7:; lis 9,-32698; andi. 0,28,1; addi 9,9,1656; stw 9,0x0(30); beq 8f; mr 3,30; bl _s800CCB84_8; 8:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s800CCB84_0();
extern "C" void _s800CCB84_1();
extern "C" void _s800CCB84_2();
extern "C" void _s800CCB84_3();
extern "C" void _s800CCB84_4();
extern "C" void _s800CCB84_5();
extern "C" void _s800CCB84_6();
extern "C" void _s800CCB84_7();
extern "C" void _s800CCB84_8();
extern "C" void f_800CCB84() {}
