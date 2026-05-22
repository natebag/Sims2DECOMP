// 0x80283518 AptAnimationPoolData::~AptAnimationPoolData(void) (688 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 22,0x8(1); stw 0,0x34(1); mr 29,3; mr 22,4; lwz 5,0xa4(29); lwz 3,-23020(13); lwz 4,0x38(29); rlwinm 5,5,2,0,29; bl _s80283518_0; lwz 9,0x2c(29); cmpwi 9,0; beq 3f; lwz 0,-8(9); rlwinm 0,0,5,0,26; add 31,9,0; cmpw 9,31; beq 2f; addi 30,31,20; 0:; addi 31,31,-32; addi 30,30,-32; mr 3,31; bl _s80283518_1; lwz 4,0x8(30); cmpwi 4,0; beq 1f; lwz 5,0x4(30); lwz 3,-23020(13); rlwinm 5,5,2,0,29; bl _s80283518_2; 1:; lwz 0,0x2c(29); cmpw 0,31; bne 0b; 2:; lwz 3,0x2c(29); addi 3,3,-8; bl _s80283518_3; 3:; lwz 3,0x14(29); cmpwi 3,0; beq 4f; bl _s80283518_4; 4:; lwz 5,0x9c(29); lwz 3,-23020(13); lwz 4,0x0(29); rlwinm 5,5,2,0,29; bl _s80283518_5; lwz 31,0x98(29); cmpwi 31,0; beq 6f; lwz 3,0x0(31); cmpwi 3,0; beq 5f; bl _s80283518_6; 5:; mr 3,31; li 4,20; bl _s80283518_7; 6:; addi 3,29,40; li 4,2; bl _s80283518_8; addi 31,29,32; lhz 0,0x2(31); li 28,0; lhz 30,0x20(29); addi 27,29,24; cmpw 28,0; addi 25,29,8; bge 9f; lis 23,-32704; lis 24,-32704; li 26,0; 7:; lwz 9,0x4(31); lwzx 11,26,9; cmpwi 11,0; beq 8f; lwz 9,0x8(11); addi 4,23,11624; addi 5,24,11664; li 6,25; lha 3,0x10(9); lwz 0,0x14(9); add 3,11,3; mtspr 8,0; blrl; addic. 30,30,-1; beq 9f; 8:; lhz 0,0x2(31); addi 28,28,1; addi 26,26,4; cmpw 28,0; blt 7b; 9:; lhz 5,0x2(31); li 30,0; lwz 4,0x4(31); lwz 3,-23020(13); rlwinm 5,5,2,0,29; bl _s80283518_9; lhz 0,0x2(27); lhz 31,0x18(29); cmpw 30,0; bge 12f; lis 24,-32704; lis 26,-32704; li 28,0; 10:; lwz 9,0x4(27); lwzx 11,28,9; cmpwi 11,0; beq 11f; lwz 9,0x8(11); addi 4,24,11748; addi 5,26,11664; li 6,25; lha 3,0x10(9); lwz 0,0x14(9); add 3,11,3; mtspr 8,0; blrl; addic. 31,31,-1; beq 12f; 11:; lhz 0,0x2(27); addi 30,30,1; addi 28,28,4; cmpw 30,0; blt 10b; 12:; lhz 5,0x2(27); li 30,0; lwz 4,0x4(27); lwz 3,-23020(13); rlwinm 5,5,2,0,29; bl _s80283518_10; lhz 0,0x2(25); lhz 31,0x8(29); cmpw 30,0; bge 15f; lis 26,-32704; lis 27,-32704; li 28,0; 13:; lwz 9,0x4(25); lwzx 11,28,9; cmpwi 11,0; beq 14f; lwz 9,0x8(11); addi 4,26,11624; addi 5,27,11664; li 6,25; lha 3,0x10(9); lwz 0,0x14(9); add 3,11,3; mtspr 8,0; blrl; addic. 31,31,-1; beq 15f; 14:; lhz 0,0x2(25); addi 30,30,1; addi 28,28,4; cmpw 30,0; blt 13b; 15:; lhz 5,0x2(25); lwz 4,0x4(25); lwz 3,-23020(13); rlwinm 5,5,2,0,29; bl _s80283518_11; andi. 0,22,1; beq 16f; lwz 3,-23020(13); mr 4,29; li 5,172; bl _s80283518_12; 16:; lwz 0,0x34(1); mtspr 8,0; lmw 22,0x8(1); addi 1,1,48"
extern "C" void _s80283518_0();
extern "C" void _s80283518_1();
extern "C" void _s80283518_2();
extern "C" void _s80283518_3();
extern "C" void _s80283518_4();
extern "C" void _s80283518_5();
extern "C" void _s80283518_6();
extern "C" void _s80283518_7();
extern "C" void _s80283518_8();
extern "C" void _s80283518_9();
extern "C" void _s80283518_10();
extern "C" void _s80283518_11();
extern "C" void _s80283518_12();
extern "C" void f_80283518() {}
