// 0x80246D1C _setlocale_r (436 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; mfcr 12; stmw 27,0xc(1); stw 0,0x24(1); stw 12,0x8(1); mr 27,3; mr 30,4; mr. 31,5; beq 7f; cmpwi 4,30,2; beq cr4,1f; lis 4,-32704; mr 3,31; addi 4,4,212; bl _s80246D1C_0; cmpwi 3,0; beq 0f; lis 4,-32704; mr 3,31; addi 4,4,204; bl _s80246D1C_1; cmpwi 3,0; beq 0f; li 3,0; b 9f; 0:; cmpwi 30,0; bne 6f; addi 4,13,-27964; addi 3,13,-27956; bl _s80246D1C_2; addi 3,13,-27964; mr 4,31; bl _s80246D1C_3; b 4f; 1:; lis 29,-32704; mr 3,31; addi 4,29,212; lis 28,-32704; bl _s80246D1C_4; cmpwi 3,0; beq 2f; lis 4,-32704; mr 3,31; addi 4,4,204; bl _s80246D1C_5; cmpwi 3,0; beq 2f; addi 4,29,212; mr 3,31; bl _s80246D1C_6; cmpwi 3,0; beq 2f; addi 4,28,216; mr 3,31; bl _s80246D1C_7; cmpwi 3,0; beq 2f; lis 4,-32704; mr 3,31; addi 4,4,224; bl _s80246D1C_8; cmpwi 3,0; beq 2f; lis 4,-32704; mr 3,31; addi 4,4,232; bl _s80246D1C_9; cmpwi 3,0; li 3,0; bne 9f; 2:; addi 4,13,-27964; addi 3,13,-27956; bl _s80246D1C_10; mr 4,31; addi 3,13,-27964; bl _s80246D1C_11; lis 4,-32704; mr 3,31; addi 4,4,216; bl _s80246D1C_12; cmpwi 3,0; bne 3f; li 0,8; b 5f; 3:; mr 3,31; bl _s80246D1C_13; cmplwi 3,1; li 0,2; bgt 5f; 4:; li 0,1; 5:; stw 0,-27968(13); 6:; stw 31,0x34(27); stw 30,0x30(27); bne cr4,8f; addi 3,13,-27956; b 9f; 7:; cmpwi 30,2; addi 3,13,-27964; beq 9f; 8:; lis 3,-32704; addi 3,3,212; 9:; lwz 0,0x24(1); lwz 12,0x8(1); mtspr 8,0; lmw 27,0xc(1); mtcrf 8,12; addi 1,1,32"
extern "C" void _s80246D1C_0();
extern "C" void _s80246D1C_1();
extern "C" void _s80246D1C_2();
extern "C" void _s80246D1C_3();
extern "C" void _s80246D1C_4();
extern "C" void _s80246D1C_5();
extern "C" void _s80246D1C_6();
extern "C" void _s80246D1C_7();
extern "C" void _s80246D1C_8();
extern "C" void _s80246D1C_9();
extern "C" void _s80246D1C_10();
extern "C" void _s80246D1C_11();
extern "C" void _s80246D1C_12();
extern "C" void _s80246D1C_13();
extern "C" void f_80246D1C() {}
