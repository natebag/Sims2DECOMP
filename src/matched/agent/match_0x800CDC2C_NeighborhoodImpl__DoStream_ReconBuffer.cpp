// 0x800CDC2C NeighborhoodImpl::DoStream(ReconBuffer (268 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 31,3; mr 29,4; mr 28,5; lha 30,0x86(31); mr 3,29; addi 4,31,132; li 5,36; bl _s800CDC2C_0; lwz 0,0xc(29); cmpwi 0,0; bne 2f; rlwinm 0,30,0,16,31; sth 30,0x86(31); cmplwi 0,1; lwz 30,-21432(13); ble 0f; lwz 9,0x0(31); li 4,1; li 5,0; lha 3,0x88(9); lwz 0,0x8c(9); add 3,31,3; mtspr 8,0; blrl; 0:; lbz 5,0x32c(30); rlwinm 0,5,0,24,31; cmpwi 0,255; beq 1f; lwz 9,0x0(31); li 4,1; lha 3,0x88(9); lwz 0,0x8c(9); add 3,31,3; mtspr 8,0; blrl; 1:; lbz 5,0x32d(30); rlwinm 0,5,0,24,31; cmpwi 0,255; beq 2f; lwz 9,0x0(31); li 4,2; lha 3,0x88(9); lwz 0,0x8c(9); add 3,31,3; mtspr 8,0; blrl; 2:; mr 3,29; addi 4,31,4; bl _s800CDC2C_1; cmpwi 28,92; bgt 3f; li 0,0; sth 0,0x6c(31); b 4f; 3:; mr 3,29; addi 4,31,108; li 5,1; bl _s800CDC2C_2; 4:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s800CDC2C_0();
extern "C" void _s800CDC2C_1();
extern "C" void _s800CDC2C_2();
extern "C" void f_800CDC2C() {}
