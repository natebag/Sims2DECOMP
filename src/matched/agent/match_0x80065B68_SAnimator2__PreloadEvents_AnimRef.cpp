// 0x80065B68 SAnimator2::PreloadEvents(AnimRef (264 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 26,0x18(1); stw 0,0x34(1); mr 28,3; lwz 4,0x0(4); lis 3,-32693; li 30,0; addi 3,3,11064; bl _s80065B68_0; mr 31,3; addi 3,1,8; bl _s80065B68_1; cmpwi 31,0; beq 0f; addi 9,31,136; addi 3,1,8; mr 4,9; lwz 30,0x4(9); bl _s80065B68_2; 0:; cmpwi 30,0; ble 5f; lis 26,-32692; lis 27,-32692; li 29,0; 1:; lwz 0,0x8(1); add 9,0,29; lwz 0,0x4(9); cmpwi 0,9; ble 2f; cmpwi 0,10; beq 3f; b 4f; 2:; cmpwi 0,6; bge 4f; cmpwi 0,0; blt 4f; cmpwi 0,4; ble 4f; lwz 4,0x8(9); addi 3,26,-14084; bl _s80065B68_3; b 4f; 3:; lwz 4,0x8(9); addi 3,27,-4004; li 5,0; li 6,0; bl _s80065B68_4; mr. 31,3; beq 4f; mr 3,28; mr 4,31; bl _s80065B68_5; mr 3,31; bl _s80065B68_6; 4:; addi 29,29,12; addic. 30,30,-1; bne 1b; 5:; addi 3,1,8; li 4,2; bl _s80065B68_7; lwz 0,0x34(1); mtspr 8,0; lmw 26,0x18(1); addi 1,1,48"
extern "C" void _s80065B68_0();
extern "C" void _s80065B68_1();
extern "C" void _s80065B68_2();
extern "C" void _s80065B68_3();
extern "C" void _s80065B68_4();
extern "C" void _s80065B68_5();
extern "C" void _s80065B68_6();
extern "C" void _s80065B68_7();
extern "C" void f_80065B68() {}
