// 0x80096080 StateMachine::DeleteAllStates(void) (308 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-64(1); mfspr 0,8; stmw 26,0x28(1); stw 0,0x44(1); mr 31,3; addi 29,1,8; addi 30,31,60; addi 26,1,32; mr 3,30; bl _s80096080_0; lis 9,-32706; li 0,0; lfs f0,-30548(9); addi 11,31,44; stw 0,0x4(30); stfs f0,0x10(30); lwz 30,0x2c(31); lwz 0,0x4(11); cmpw 30,0; beq 2f; mr 28,11; li 27,0; 0:; lwz 11,0x0(30); cmpwi 11,0; beq 1f; lwz 9,0x18(11); li 4,3; lha 3,0x8(9); lwz 0,0xc(9); add 3,11,3; mtspr 8,0; blrl; 1:; stw 27,0x0(30); addi 30,30,4; lwz 0,0x4(28); cmpw 30,0; bne 0b; 2:; li 0,0; addi 8,29,8; stw 0,0x8(1); addi 7,31,52; stw 0,0x4(29); stw 0,0x4(8); lwz 0,0x30(31); lwz 9,0x2c(31); lwz 11,0x8(1); lwz 10,0xc(1); stw 9,0x8(1); stw 0,0xc(1); stw 11,0x2c(31); lwz 0,0x4(8); stw 10,0x30(31); stw 0,0x4(26); lwz 9,0x34(31); lwz 0,0x4(7); stw 9,0x8(29); stw 0,0x4(8); lwz 9,0x20(1); lwz 0,0x24(1); stw 9,0x34(31); stw 0,0x4(7); lwz 3,0x8(1); cmpwi 3,0; beq 4f; lwz 0,0xc(29); subf 0,3,0; rlwinm 4,0,0,0,29; cmplwi 4,128; ble 3f; bl _s80096080_1; b 4f; 3:; bl _s80096080_2; 4:; lwz 0,0x44(1); mtspr 8,0; lmw 26,0x28(1); addi 1,1,64"
extern "C" void _s80096080_0();
extern "C" void _s80096080_1();
extern "C" void _s80096080_2();
extern "C" void f_80096080() {}
