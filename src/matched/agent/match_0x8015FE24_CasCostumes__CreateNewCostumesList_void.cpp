// 0x8015FE24 CasCostumes::CreateNewCostumesList(void) (540 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-72(1); mfspr 0,8; stmw 20,0x18(1); stw 0,0x4c(1); mr 25,3; addi 23,1,8; lis 20,-32746; bl _s8015FE24_0; lis 9,-32702; li 4,0; addi 21,9,17564; 0:; addi 22,4,1; li 27,0; rlwinm 26,4,4,0,27; subfic 0,4,0; adde 24,0,4; 1:; li 3,292; bl _s8015FE24_1; bl _s8015FE24_2; stw 3,0x8(1); mr 4,24; bl _s8015FE24_3; lwz 4,0x8(1); rlwinm 0,27,2,0,29; lwzx 3,21,0; li 5,32; addi 4,4,4; bl _s8015FE24_4; cmpwi 24,0; beq 2f; lwz 4,0x8(1); lis 3,-32706; addi 3,3,-4564; li 5,32; addi 4,4,68; bl _s8015FE24_5; b 3f; 2:; lwz 4,0x8(1); lis 3,-32706; addi 3,3,-4556; li 5,32; addi 4,4,68; bl _s8015FE24_6; 3:; add 31,26,25; lwz 30,0x4(31); lwz 0,0xc(31); cmpw 30,0; beq 4f; lwz 0,0x8(1); addi 27,27,1; stw 0,0x0(30); lwz 9,0x4(31); addi 9,9,4; stw 9,0x4(31); b 15f; 4:; lwzx 0,26,25; li 9,1; stw 9,0x10(1); addi 10,1,16; subf 0,0,30; addi 11,1,12; srawi 9,0,2; stw 9,0xc(1); cmplwi 9,1; bge 5f; mr 11,10; 5:; lwz 0,0x0(11); add. 0,9,0; beq 7f; rlwinm 0,0,2,0,29; mr 28,0; cmplwi 0,128; ble 6f; mr 3,28; bl _s8015FE24_7; mr 29,3; b 8f; 6:; mr 3,28; bl _s8015FE24_8; mr 29,3; b 8f; 7:; li 29,0; li 28,0; 8:; lwz 4,0x0(31); cmpw 30,4; beq 9f; subf 30,4,30; mr 3,29; mr 5,30; bl _s8015FE24_9; add 0,3,30; b 10f; 9:; mr 0,29; 10:; lwz 9,0x10(1); mr 30,0; addi 27,27,1; mtspr 9,9; cmpwi 9,0; beq 12f; 11:; lwz 0,0x0(23); stw 0,0x0(30); addi 30,30,4; bdnz 11b; 12:; lwz 3,0x0(31); lwz 0,0xc(31); cmpwi 3,0; subf 0,3,0; srawi 0,0,2; beq 14f; rlwinm 4,0,2,0,29; cmplwi 4,128; ble 13f; bl _s8015FE24_10; b 14f; 13:; bl _s8015FE24_11; 14:; add 0,28,29; stw 29,0x0(31); stw 0,0xc(31); stw 30,0x4(31); 15:; rlwinm 27,27,0,24,31; cmplwi 27,80; ble 1b; add 9,26,25; lwzx 3,26,25; lwz 4,0x4(9); addi 5,20,-2592; bl _s8015FE24_12; rlwinm 4,22,0,24,31; cmplwi 4,1; ble 0b; lwz 0,0x4c(1); mtspr 8,0; lmw 20,0x18(1); addi 1,1,72"
extern "C" void _s8015FE24_0();
extern "C" void _s8015FE24_1();
extern "C" void _s8015FE24_2();
extern "C" void _s8015FE24_3();
extern "C" void _s8015FE24_4();
extern "C" void _s8015FE24_5();
extern "C" void _s8015FE24_6();
extern "C" void _s8015FE24_7();
extern "C" void _s8015FE24_8();
extern "C" void _s8015FE24_9();
extern "C" void _s8015FE24_10();
extern "C" void _s8015FE24_11();
extern "C" void _s8015FE24_12();
extern "C" void f_8015FE24() {}
