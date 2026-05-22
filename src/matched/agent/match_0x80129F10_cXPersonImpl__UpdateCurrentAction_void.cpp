// 0x80129F10 cXPersonImpl::UpdateCurrentAction(void) (316 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-88(1); mfspr 0,8; stmw 30,0x50(1); stw 0,0x5c(1); mr 31,3; addi 30,1,8; mr 3,30; bl _s80129F10_0; lwz 0,0x534(31); cmpwi 0,0; beq 1f; addi 11,31,304; lwz 9,0x2a8(11); lwz 0,0x2ac(11); cmpw 0,9; bne 0f; mr 3,30; mr 4,30; bl _s80129F10_1; b 2f; 0:; lis 4,-13108; mr 3,30; ori 4,4,52429; mulhwu 4,9,4; rlwinm 4,4,29,3,31; mulli 4,4,10; subf 4,4,9; mulli 4,4,68; add 4,11,4; bl _s80129F10_2; b 2f; 1:; mr 3,30; mr 4,30; bl _s80129F10_3; 2:; mr 3,30; bl _s80129F10_4; cmpwi 3,0; beq 3f; li 0,0; sth 0,0x56(31); sth 0,0x54(31); 3:; lwz 0,0x28(30); addi 10,31,996; lwz 11,0x3e4(31); sth 0,0x4a(31); lwz 0,0x4(10); mr 9,11; cmpw 11,0; beq 5f; 4:; addi 9,9,12; cmpw 9,0; bne 4b; 5:; stw 11,0x4(10); lha 0,0x9a(31); cmpwi 0,0; beq 6f; li 0,0; lwz 9,0x0(31); sth 0,0x9a(31); addi 5,9,112; addi 4,9,104; lwz 10,0x4(9); lwz 11,0x4(10); lha 3,0x1b8(11); lwz 0,0x1bc(11); add 3,10,3; mtspr 8,0; blrl; 6:; li 0,0; addi 3,1,8; sth 0,0x96(31); li 4,2; sth 0,0x98(31); bl _s80129F10_5; lwz 0,0x5c(1); mtspr 8,0; lmw 30,0x50(1); addi 1,1,88"
extern "C" void _s80129F10_0();
extern "C" void _s80129F10_1();
extern "C" void _s80129F10_2();
extern "C" void _s80129F10_3();
extern "C" void _s80129F10_4();
extern "C" void _s80129F10_5();
extern "C" void f_80129F10() {}
