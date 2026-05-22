// 0x80058BFC OptionsRecon::WriteOut(void) (296 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; mfcr 12; stmw 29,0xc(1); stw 0,0x1c(1); stw 12,0x8(1); mr 30,3; bl _s80058BFC_0; li 7,0; li 6,0; li 4,8192; li 5,32; bl _s80058BFC_1; mr 31,3; li 4,0; addi 29,31,8; li 5,8184; mr 3,29; bl _s80058BFC_2; mr 3,30; li 4,0; li 5,9; bl _s80058BFC_3; mr 30,3; li 5,0; lwz 4,0x4(30); cmpwi 4,30,0; beq cr4,0f; lwz 5,0x0(30); 0:; mr 3,29; crxor 6,6,6; bl _s80058BFC_4; beq cr4,2f; lwz 0,0x8(30); cmpwi 0,0; beq 1f; bl _s80058BFC_5; lwz 4,0x4(30); bl _s80058BFC_6; 1:; bl _s80058BFC_7; mr 4,30; bl _s80058BFC_8; 2:; li 4,8184; addi 3,31,8; bl _s80058BFC_9; stw 3,0x0(31); li 5,12; li 6,0; li 4,9; li 3,70; bl _s80058BFC_10; stw 3,0x4(31); li 4,8192; mr 3,31; bl _s80058BFC_11; lwz 11,-26524(13); mr 30,3; lwz 9,0x20(11); lha 3,0x28(9); lwz 0,0x2c(9); add 3,11,3; mtspr 8,0; blrl; bl _s80058BFC_12; mr 4,31; bl _s80058BFC_13; mr 3,30; lwz 0,0x1c(1); lwz 12,0x8(1); mtspr 8,0; lmw 29,0xc(1); mtcrf 8,12; addi 1,1,24"
extern "C" void _s80058BFC_0();
extern "C" void _s80058BFC_1();
extern "C" void _s80058BFC_2();
extern "C" void _s80058BFC_3();
extern "C" void _s80058BFC_4();
extern "C" void _s80058BFC_5();
extern "C" void _s80058BFC_6();
extern "C" void _s80058BFC_7();
extern "C" void _s80058BFC_8();
extern "C" void _s80058BFC_9();
extern "C" void _s80058BFC_10();
extern "C" void _s80058BFC_11();
extern "C" void _s80058BFC_12();
extern "C" void _s80058BFC_13();
extern "C" void f_80058BFC() {}
