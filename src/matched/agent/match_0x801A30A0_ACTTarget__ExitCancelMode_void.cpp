// 0x801A30A0 ACTTarget::ExitCancelMode(void) (124 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 30,0x20(1); stw 0,0x2c(1); mr 30,3; li 9,0; lwz 0,0x648(30); stw 9,0x648(30); stw 0,0x64c(30); stw 9,0x644(30); bl _s801A30A0_0; addi 3,1,8; bl _s801A30A0_1; lwz 6,0xdc(30); lis 4,-32705; addi 3,1,8; li 5,0; addi 4,4,-8784; bl _s801A30A0_2; lis 9,-32697; lwz 4,0xdc(30); lwz 3,0x5bcc(9); bl _s801A30A0_3; addi 3,1,8; li 4,2; bl _s801A30A0_4; lwz 0,0x2c(1); mtspr 8,0; lmw 30,0x20(1); addi 1,1,40"
extern "C" void _s801A30A0_0();
extern "C" void _s801A30A0_1();
extern "C" void _s801A30A0_2();
extern "C" void _s801A30A0_3();
extern "C" void _s801A30A0_4();
extern "C" void f_801A30A0() {}
