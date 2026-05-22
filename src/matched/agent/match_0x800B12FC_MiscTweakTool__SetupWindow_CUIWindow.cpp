// 0x800B12FC MiscTweakTool::SetupWindow(CUIWindow (924 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="bne 0f; mr 3,31; bl _s800B12FC_0; 0:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16; blr; stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); li 0,0; ori 0,0,65535; cmpw 4,0; bne 2f; cmpwi 3,0; beq 1f; lis 3,-32696; addi 3,3,24032; bl _s800B12FC_1; b 2f; 1:; lis 9,-32696; lis 11,-32697; addi 30,9,24032; addi 11,11,-24248; addi 3,30,28; li 4,2; stw 11,0x5de0(9); bl _s800B12FC_2; mr 3,30; li 4,2; bl _s800B12FC_3; 2:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16; blr; stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); li 4,0; li 3,1; ori 4,4,65535; bl _s800B12FC_4; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8; blr; stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); li 4,0; li 3,0; ori 4,4,65535; bl _s800B12FC_5; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8; blr; stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lis 9,-32698; andi. 0,4,1; addi 9,9,-5696; stw 9,0x0(3); beq 3f; bl _s800B12FC_6; 3:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8; blr; stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); bl _s800B12FC_7; li 4,32; li 5,1; li 6,0; bl _s800B12FC_8; lis 9,-32698; mr 11,3; addi 9,9,-5832; stw 9,0x0(11); lwz 0,0xc(1); mtspr 8,0; addi 1,1,8; blr; stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); mr. 11,3; beq 4f; lwz 9,0x0(11); li 4,3; lha 3,0x8(9); lwz 0,0xc(9); add 3,11,3; mtspr 8,0; blrl; 4:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8; blr; lwz 3,0x0(3); li 11,0; cmpwi 3,0; beq 5f; lwz 11,-4(3); 5:; li 10,0; cmpwi 11,0; bne 6f; li 3,0; 6:; li 9,0; b 8f; 7:; addi 9,9,1; addi 3,3,12; 8:; cmpw 9,11; bge 9f; lwz 0,0x4(3); cmpw 0,5; bne 7b; lha 0,0x8(3); cmpw 0,4; bne 7b; mr 10,3; 9:; mr 3,10; blr; stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; lwz 9,0x0(31); addi 30,31,8; lwz 0,0x1c(9); lha 3,0x18(9); mtspr 8,0; add 3,31,3; blrl; lis 3,-32692; lis 4,20288; ori 4,4,50412; li 6,0; li 5,0; addi 3,3,-20832; bl _s800B12FC_9; mr 0,3; lis 4,-32706; addi 4,4,-26620; stw 0,0x4(31); bl _s800B12FC_10; mr. 3,3; cmpwi 30,0; beq 10f; stw 3,0x8(31); 10:; lis 4,-32706; lwz 3,0x4(31); addi 4,4,-26612; addi 30,31,12; bl _s800B12FC_11; mr 29,3; lis 5,-32706; lwz 3,0x4(31); addi 5,5,-26600; mr 4,29; bl _s800B12FC_12; cmpwi 30,0; beq 11f; stw 3,0xc(31); 11:; lis 5,-32706; lwz 3,0x4(31); mr 4,29; addi 5,5,-26592; bl _s800B12FC_13; addi 0,31,16; cmpwi 0,0; beq 12f; stw 3,0x10(31); 12:; li 0,0; addi 11,31,20; addi 9,31,24; sth 0,0x14(31); stw 9,0x1c(31); stw 11,0x18(31); lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24; blr; stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lwz 3,0x4(31); cmpwi 3,0; beq 13f; bl _s800B12FC_14; li 0,0; stw 0,0x10(31); stw 0,0x4(31); stw 0,0x8(31); stw 0,0xc(31); 13:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16; blr; lwz 9,0x8(3); li 10,0; li 3,0; lwz 11,0xc(9); lwz 9,0x4(9); cmplw 3,11; bgelr; lwz 0,0x0(9); cmpw 0,4; bne 14f; mr 3,9; blr; 14:; addi 10,10,1; addi 9,9,20; cmplw 10,11; bgelr; lwz 0,0x0(9); cmpw 0,4; bne 14b; mr 3,9"
extern "C" void _s800B12FC_0();
extern "C" void _s800B12FC_1();
extern "C" void _s800B12FC_2();
extern "C" void _s800B12FC_3();
extern "C" void _s800B12FC_4();
extern "C" void _s800B12FC_5();
extern "C" void _s800B12FC_6();
extern "C" void _s800B12FC_7();
extern "C" void _s800B12FC_8();
extern "C" void _s800B12FC_9();
extern "C" void _s800B12FC_10();
extern "C" void _s800B12FC_11();
extern "C" void _s800B12FC_12();
extern "C" void _s800B12FC_13();
extern "C" void _s800B12FC_14();
extern "C" void f_800B12FC() {}
