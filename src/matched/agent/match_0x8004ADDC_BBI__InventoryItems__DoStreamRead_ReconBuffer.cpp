// 0x8004ADDC BBI::InventoryItems::DoStreamRead(ReconBuffer (312 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; mfcr 12; stmw 23,0x14(1); stw 0,0x3c(1); stw 12,0x10(1); mr 26,3; mr 29,4; mr 27,5; bl _s8004ADDC_0; li 28,0; mr 3,26; li 23,1; bl _s8004ADDC_1; mr 25,3; cmplw 28,25; bge 4f; cmpwi 4,27,9; li 24,0; mr 30,26; 0:; bgt cr4,1f; addi 4,1,12; stw 24,0xc(1); mr 3,29; li 5,1; bl _s8004ADDC_2; lwz 4,0xc(1); cmpwi 4,0; beq 3f; mr 3,26; bl _s8004ADDC_3; mr. 31,3; beq 3f; lwz 9,0x8(31); mr 4,29; mr 5,27; lha 3,0x10(9); lwz 0,0x14(9); add 3,31,3; mtspr 8,0; blrl; cmpwi 3,0; bne 2f; li 23,0; b 2f; 1:; stb 24,0x8(1); mr 3,29; addi 4,1,8; li 5,1; bl _s8004ADDC_4; lbz 0,0x8(1); cmpwi 0,0; beq 3f; li 3,12; bl _s8004ADDC_5; bl _s8004ADDC_6; mr 31,3; mr 4,29; lwz 9,0x8(31); mr 5,27; lha 3,0x10(9); lwz 0,0x14(9); add 3,31,3; mtspr 8,0; blrl; 2:; stw 31,0x0(30); 3:; addi 28,28,1; addi 30,30,4; cmplw 28,25; blt 0b; 4:; mr 3,23; lwz 0,0x3c(1); lwz 12,0x10(1); mtspr 8,0; lmw 23,0x14(1); mtcrf 8,12; addi 1,1,56"
extern "C" void _s8004ADDC_0();
extern "C" void _s8004ADDC_1();
extern "C" void _s8004ADDC_2();
extern "C" void _s8004ADDC_3();
extern "C" void _s8004ADDC_4();
extern "C" void _s8004ADDC_5();
extern "C" void _s8004ADDC_6();
extern "C" void f_8004ADDC() {}
