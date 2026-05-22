// 0x80161BCC CasMediator::CasMediator(void) (188 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 30,0x18(1); stw 0,0x24(1); mr 31,3; li 30,0; stw 30,0x4(31); li 3,20; bl _s80161BCC_0; stw 3,0x4(31); stw 30,0x8(31); stb 30,0xc(31); stw 30,0x0(3); lwz 11,0x4(31); stw 30,0x4(11); lwz 9,0x4(31); stw 9,0x8(9); lwz 11,0x4(31); stw 11,0xc(11); stw 30,0x10(31); lwz 0,0x8(31); stw 30,0x14(31); cmpwi 0,0; stw 30,0x18(31); stw 30,0x1c(31); stw 30,0x28(31); stw 30,0x2c(31); beq 0f; lwz 9,0x4(31); mr 3,31; lwz 4,0x4(9); bl _s80161BCC_1; lwz 9,0x4(31); stw 9,0x8(9); lwz 11,0x4(31); stw 30,0x4(11); lwz 9,0x4(31); stw 9,0xc(9); stw 30,0x8(31); 0:; stw 30,0x24(31); mr 3,31; stw 30,0x20(31); lwz 0,0x24(1); mtspr 8,0; lmw 30,0x18(1); addi 1,1,32"
extern "C" void _s80161BCC_0();
extern "C" void _s80161BCC_1();
extern "C" void f_80161BCC() {}
