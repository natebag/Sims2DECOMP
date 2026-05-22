// 0x80195000 CASTarget::SaveNameEnterCBA(void) (196 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 28,3; li 30,0; lis 3,-32705; li 31,0; addi 3,3,-16192; bl _s80195000_0; mr. 29,3; beq 0f; cmpwi 29,1; beq 1f; b 3f; 0:; lis 3,-32705; addi 3,3,-16164; bl _s80195000_1; mr 30,3; lis 3,-32705; addi 3,3,-16116; b 2f; 1:; lis 3,-32705; addi 3,3,-16072; bl _s80195000_2; mr 30,3; lis 3,-32705; addi 3,3,-16024; 2:; bl _s80195000_3; mr 31,3; 3:; cmplwi 29,1; bgt 4f; lwz 3,0x84(28); bl _s80195000_4; mr 4,30; li 5,32; addi 3,3,4; bl _s80195000_5; lwz 3,0x84(28); bl _s80195000_6; mr 4,31; addi 3,3,68; li 5,32; bl _s80195000_7; 4:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s80195000_0();
extern "C" void _s80195000_1();
extern "C" void _s80195000_2();
extern "C" void _s80195000_3();
extern "C" void _s80195000_4();
extern "C" void _s80195000_5();
extern "C" void _s80195000_6();
extern "C" void _s80195000_7();
extern "C" void f_80195000() {}
