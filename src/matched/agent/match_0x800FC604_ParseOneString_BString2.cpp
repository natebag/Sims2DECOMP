// 0x800FC604 ParseOneString(BString2 (472 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-72(1); mfspr 0,8; mfcr 12; stmw 24,0x28(1); stw 0,0x4c(1); stw 12,0x24(1); mr 30,3; mr 31,4; mr 24,6; mr 26,7; mr 25,8; li 28,-1; bl _s800FC604_0; mr 27,3; cmpwi 27,-1; beq 9f; mr 3,31; bl _s800FC604_1; add 31,27,3; mr 3,30; bl _s800FC604_2; mr 29,3; stw 28,0x0(26); stw 28,0x0(25); cmpw 31,29; bge 8f; mr 3,30; mr 4,31; bl _s800FC604_3; cmpwi 3,58; bne 8f; addi 3,1,8; addi 31,31,1; li 5,16; addi 4,3,8; bl _s800FC604_4; b 1f; 0:; mr 4,31; mr 3,30; bl _s800FC604_5; addi 31,31,1; extsb 4,3; addi 3,1,8; bl _s800FC604_6; 1:; cmpw cr4,31,29; bge cr4,2f; mr 3,30; mr 4,31; bl _s800FC604_7; cmplwi 3,255; bgt 2f; mr 4,31; mr 3,30; bl _s800FC604_8; bl _s800FC604_9; cmpwi 3,0; bne 0b; 2:; addi 3,1,8; bl _s800FC604_10; cmpwi 3,0; beq 3f; addi 3,1,8; bl _s800FC604_11; bl _s800FC604_12; stw 3,0x0(26); 3:; bge cr4,8f; mr 3,30; mr 4,31; bl _s800FC604_13; cmpwi 3,58; beq 4f; mr 3,30; mr 4,31; bl _s800FC604_14; cmpwi 3,44; bne 8f; 4:; addi 31,31,1; addi 3,1,8; bl _s800FC604_15; b 6f; 5:; mr 4,31; mr 3,30; bl _s800FC604_16; addi 31,31,1; extsb 4,3; addi 3,1,8; bl _s800FC604_17; 6:; cmpw 31,29; bge 7f; mr 3,30; mr 4,31; bl _s800FC604_18; cmplwi 3,255; bgt 7f; mr 4,31; mr 3,30; bl _s800FC604_19; bl _s800FC604_20; cmpwi 3,0; bne 5b; 7:; addi 3,1,8; bl _s800FC604_21; cmpwi 3,0; beq 8f; addi 3,1,8; bl _s800FC604_22; bl _s800FC604_23; stw 3,0x0(25); 8:; subf 0,27,31; mr 3,27; stw 0,0x0(24); 9:; lwz 0,0x4c(1); lwz 12,0x24(1); mtspr 8,0; lmw 24,0x28(1); mtcrf 8,12; addi 1,1,72"
extern "C" void _s800FC604_0();
extern "C" void _s800FC604_1();
extern "C" void _s800FC604_2();
extern "C" void _s800FC604_3();
extern "C" void _s800FC604_4();
extern "C" void _s800FC604_5();
extern "C" void _s800FC604_6();
extern "C" void _s800FC604_7();
extern "C" void _s800FC604_8();
extern "C" void _s800FC604_9();
extern "C" void _s800FC604_10();
extern "C" void _s800FC604_11();
extern "C" void _s800FC604_12();
extern "C" void _s800FC604_13();
extern "C" void _s800FC604_14();
extern "C" void _s800FC604_15();
extern "C" void _s800FC604_16();
extern "C" void _s800FC604_17();
extern "C" void _s800FC604_18();
extern "C" void _s800FC604_19();
extern "C" void _s800FC604_20();
extern "C" void _s800FC604_21();
extern "C" void _s800FC604_22();
extern "C" void _s800FC604_23();
extern "C" void f_800FC604() {}
