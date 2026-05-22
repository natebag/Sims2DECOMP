// 0x8004B7C8 IngredientManager::MixIngredients(short, (280 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stmw 24,0x18(1); stw 0,0x3c(1); mr 3,4; li 9,0; mr 4,5; addi 0,1,8; mr 5,6; li 10,0; mr 6,7; mr 25,0; stw 9,0x8(1); stw 10,0xc(1); mr 7,0; bl _s8004B7C8_0; cmpwi 3,0; beq 4f; lis 9,-32697; lis 4,-32707; lwz 3,0x5ec4(9); addi 4,4,11996; bl _s8004B7C8_1; mr 26,3; b 1f; 0:; mr 3,30; b 5f; 1:; lwz 27,0xc(26); li 29,0; cmplw 29,27; bge 4f; addi 31,1,16; lis 24,-32763; li 28,0; 2:; lwz 0,0x4(26); mr 4,31; add 30,0,28; mr 3,30; bl _s8004B7C8_2; mr 3,31; li 4,4; li 5,2; addi 6,24,-19048; bl _s8004B7C8_3; lha 9,0x8(1); lha 0,0x10(1); cmpw 9,0; bne 3f; lhz 9,0x2(25); lhz 0,0x2(31); cmpw 9,0; bne 3f; lhz 9,0x4(25); lhz 0,0x4(31); cmpw 9,0; bne 3f; lhz 9,0x6(25); lhz 0,0x6(31); cmpw 9,0; beq 0b; 3:; addi 29,29,1; addi 28,28,72; cmplw 29,27; blt 2b; 4:; li 3,0; 5:; lwz 0,0x3c(1); mtspr 8,0; lmw 24,0x18(1); addi 1,1,56"
extern "C" void _s8004B7C8_0();
extern "C" void _s8004B7C8_1();
extern "C" void _s8004B7C8_2();
extern "C" void _s8004B7C8_3();
extern "C" void f_8004B7C8() {}
