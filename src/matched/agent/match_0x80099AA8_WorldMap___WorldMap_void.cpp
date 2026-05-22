// 0x80099AA8 WorldMap::~WorldMap(void) (412 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; mr 29,4; lwz 0,0x8(31); cmpwi 0,0; beq 2f; bl _s80099AA8_0; bl _s80099AA8_1; lwz 11,0x90(31); cmpwi 11,0; beq 0f; lwz 9,0x0(11); li 4,3; lwz 0,0x34(9); lha 3,0x30(9); mtspr 8,0; add 3,11,3; blrl; li 0,0; stw 0,0x90(31); 0:; lwz 11,-26512(13); li 0,0; stw 0,0x94(31); lis 9,-32697; stw 0,0x30(11); addi 9,9,24012; stw 0,0x8(31); lwz 11,0x118(9); cmpwi 11,0; beq 1f; lwz 0,0x240(11); ori 0,0,1; stw 0,0x240(11); 1:; lwz 3,0xe0(9); bl _s80099AA8_2; mr. 3,3; beq 2f; bl _s80099AA8_3; mr. 3,3; beq 2f; lwz 0,0xc(3); cmpwi 0,1; beq 2f; li 4,0; bl _s80099AA8_4; 2:; li 30,0; lis 3,-32692; stw 30,0xc(31); lis 4,26961; addi 3,3,-27556; ori 4,4,21689; bl _s80099AA8_5; stw 30,0x10(31); lis 3,-32693; lis 4,1510; addi 3,3,11064; ori 4,4,29; bl _s80099AA8_6; stw 30,0x14(31); lis 3,-32693; lis 4,26961; addi 3,3,21144; ori 4,4,21689; bl _s80099AA8_7; stw 30,0x98(31); lis 3,-32697; addi 3,3,23428; bl _s80099AA8_8; mr 4,3; lis 3,-32692; addi 3,3,-17444; bl _s80099AA8_9; lwz 11,0x4(31); cmpwi 11,0; beq 3f; lwz 9,0x56c(11); li 4,3; lha 3,0x8(9); lwz 0,0xc(9); add 3,11,3; mtspr 8,0; blrl; stw 30,0x4(31); 3:; lis 3,-32696; lis 4,-17670; addi 3,3,32332; ori 4,4,49883; bl _s80099AA8_10; addi 3,31,24; li 4,2; bl _s80099AA8_11; andi. 0,29,1; beq 4f; mr 3,31; bl _s80099AA8_12; 4:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s80099AA8_0();
extern "C" void _s80099AA8_1();
extern "C" void _s80099AA8_2();
extern "C" void _s80099AA8_3();
extern "C" void _s80099AA8_4();
extern "C" void _s80099AA8_5();
extern "C" void _s80099AA8_6();
extern "C" void _s80099AA8_7();
extern "C" void _s80099AA8_8();
extern "C" void _s80099AA8_9();
extern "C" void _s80099AA8_10();
extern "C" void _s80099AA8_11();
extern "C" void _s80099AA8_12();
extern "C" void f_80099AA8() {}
