// 0x800EBB30 cXObjectImpl::HandleError(void) (776 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-824(1); mfspr 0,8; mfcr 12; stmw 25,0x31c(1); stw 0,0x33c(1); stw 12,0x318(1); mr 31,3; li 4,256; lwz 3,0x4(31); lwz 9,0x4(3); lha 0,0x78(9); lwz 9,0x7c(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; beq 7f; lwz 9,0x0(31); lwz 10,0x0(9); lwz 11,0x18(10); lha 3,0x30(11); lwz 0,0x34(11); add 3,10,3; mtspr 8,0; blrl; cmpwi 3,0; bne 0f; lwz 3,0x4(31); li 4,256; li 5,0; lwz 9,0x4(3); lha 0,0x70(9); lwz 9,0x74(9); add 3,3,0; mtspr 8,9; blrl; b 7f; 0:; lwz 11,0x4(31); li 4,256; li 5,0; lwz 9,0x4(11); lwz 0,0x74(9); lha 3,0x70(9); mtspr 8,0; add 3,11,3; blrl; lwz 9,0x0(31); lwz 10,0x0(9); lwz 11,0x18(10); lha 3,0x48(11); lwz 0,0x4c(11); add 3,10,3; mtspr 8,0; blrl; mr. 25,3; beq 1f; lwz 3,0x4(31); lha 4,0x4(25); lwz 9,0x4(3); lha 0,0x488(9); lwz 9,0x48c(9); add 3,3,0; mtspr 8,9; blrl; mr 27,3; b 2f; 1:; li 27,0; 2:; addi 30,1,8; li 5,256; addi 4,30,8; mr 3,30; bl _s800EBB30_0; cmpwi 4,27,0; lwz 11,0x4(31); mr 4,30; addi 29,1,528; addi 28,1,272; lwz 9,0x4(11); mr 26,29; lwz 0,0x3e4(9); lha 3,0x3e0(9); mtspr 8,0; add 3,11,3; blrl; addi 4,1,536; addi 3,1,528; li 5,256; bl _s800EBB30_1; lis 4,-32706; mr 3,29; addi 4,4,-20072; li 5,-1; bl _s800EBB30_2; mr 4,30; mr 3,29; li 5,-1; bl _s800EBB30_3; lis 4,-32706; mr 3,29; addi 4,4,-20060; li 5,-1; bl _s800EBB30_4; lwz 11,0x4(31); mr 4,28; li 5,256; lwz 9,0x4(11); lha 3,0x518(9); lwz 0,0x51c(9); add 3,11,3; mtspr 8,0; blrl; mr 4,28; mr 3,29; li 5,-1; bl _s800EBB30_5; lis 4,-32706; mr 3,29; addi 4,4,-20052; li 5,-1; bl _s800EBB30_6; beq cr4,3f; lwz 9,0x4(27); mr 4,28; li 5,256; lha 3,0x518(9); lwz 0,0x51c(9); add 3,27,3; mtspr 8,0; blrl; beq cr4,3f; mr 4,28; b 4f; 3:; lis 9,-32706; addi 4,9,-20076; 4:; mr 3,29; li 5,-1; bl _s800EBB30_7; lis 4,-32706; mr 3,26; addi 4,4,-20040; li 5,-1; bl _s800EBB30_8; cmpwi 25,0; beq 5f; lha 4,0x0(25); mr 3,26; bl _s800EBB30_9; lis 4,-32706; li 5,-1; addi 4,4,-20028; mr 3,26; bl _s800EBB30_10; lha 4,0x2(25); mr 3,26; bl _s800EBB30_11; lis 4,-32706; mr 3,26; addi 4,4,-20016; li 5,-1; bl _s800EBB30_12; lwz 11,0x10(25); mr 3,26; li 5,-1; lwz 9,0x4(11); lwz 4,0x14(9); bl _s800EBB30_13; b 6f; 5:; lis 4,-32706; mr 3,26; addi 4,4,-19996; li 5,-1; bl _s800EBB30_14; 6:; lwz 11,0x58(31); lwz 4,0x4(31); lwz 9,0x0(11); lwz 0,0x134(9); lha 3,0x130(9); mtspr 8,0; add 3,11,3; blrl; lwz 9,0xec(31); li 4,0; lha 3,0x18(9); lwz 0,0x1c(9); add 3,31,3; mtspr 8,0; blrl; 7:; lwz 0,0x33c(1); lwz 12,0x318(1); mtspr 8,0; lmw 25,0x31c(1); mtcrf 8,12; addi 1,1,824"
extern "C" void _s800EBB30_0();
extern "C" void _s800EBB30_1();
extern "C" void _s800EBB30_2();
extern "C" void _s800EBB30_3();
extern "C" void _s800EBB30_4();
extern "C" void _s800EBB30_5();
extern "C" void _s800EBB30_6();
extern "C" void _s800EBB30_7();
extern "C" void _s800EBB30_8();
extern "C" void _s800EBB30_9();
extern "C" void _s800EBB30_10();
extern "C" void _s800EBB30_11();
extern "C" void _s800EBB30_12();
extern "C" void _s800EBB30_13();
extern "C" void _s800EBB30_14();
extern "C" void f_800EBB30() {}
