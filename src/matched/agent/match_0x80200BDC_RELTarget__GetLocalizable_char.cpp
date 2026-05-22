// 0x80200BDC RELTarget::GetLocalizable(char (340 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; mr 31,4; li 3,8192; bl _s80200BDC_0; mr 29,3; li 0,0; sth 0,0x0(29); lbz 9,0x0(31); addi 9,9,-48; cmplwi 9,1; bgt 0f; addi 31,31,1; 0:; lis 3,-32704; mr 4,31; addi 3,3,-18296; bl _s80200BDC_1; cmpwi 3,0; bne 1f; addi 3,30,148; b 2f; 1:; lis 3,-32704; mr 4,31; addi 3,3,-18280; bl _s80200BDC_2; cmpwi 3,0; bne 3f; lwz 4,0x8c(30); mr 3,30; lwz 0,0x90(30); mulli 4,4,6; add 4,0,4; bl _s80200BDC_3; mr. 3,3; beq 4f; addi 3,3,20; 2:; bl _s80200BDC_4; mr 4,3; mr 3,29; bl _s80200BDC_5; b 4f; 3:; lis 3,-32704; mr 4,31; addi 3,3,-18264; bl _s80200BDC_6; cmpwi 3,0; bne 4f; lwz 4,0x8c(30); mr 3,30; lwz 0,0x90(30); mulli 4,4,6; add 4,0,4; bl _s80200BDC_7; mr. 3,3; beq 4f; addi 3,3,24; bl _s80200BDC_8; mr 4,3; mr 3,29; bl _s80200BDC_9; 4:; mr 3,29; bl _s80200BDC_10; mr 3,29; bl _s80200BDC_11; mr 3,29; bl _s80200BDC_12; mr 3,29; bl _s80200BDC_13; addi 3,3,1; rlwinm 3,3,1,0,30; bl _s80200BDC_14; mr 30,3; mr 4,29; bl _s80200BDC_15; mr 3,29; bl _s80200BDC_16; mr 3,30; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s80200BDC_0();
extern "C" void _s80200BDC_1();
extern "C" void _s80200BDC_2();
extern "C" void _s80200BDC_3();
extern "C" void _s80200BDC_4();
extern "C" void _s80200BDC_5();
extern "C" void _s80200BDC_6();
extern "C" void _s80200BDC_7();
extern "C" void _s80200BDC_8();
extern "C" void _s80200BDC_9();
extern "C" void _s80200BDC_10();
extern "C" void _s80200BDC_11();
extern "C" void _s80200BDC_12();
extern "C" void _s80200BDC_13();
extern "C" void _s80200BDC_14();
extern "C" void _s80200BDC_15();
extern "C" void _s80200BDC_16();
extern "C" void f_80200BDC() {}
