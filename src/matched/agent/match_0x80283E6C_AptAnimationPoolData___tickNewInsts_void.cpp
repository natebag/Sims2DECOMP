// 0x80283E6C AptAnimationPoolData::_tickNewInsts(void) (308 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 26,0x8(1); stw 0,0x24(1); mr 29,3; li 27,0; lwz 0,0x4(29); cmpw 27,0; bge 5f; li 28,0; lis 26,-32704; 0:; lwz 9,0x0(29); li 30,0; lwzx 31,28,9; mr 3,31; bl _s80283E6C_0; cmpwi 3,14; bne 1f; mr 3,31; bl _s80283E6C_1; subfic 0,3,0; adde 30,0,3; 1:; cmpwi 30,0; beq 2f; lwz 9,0x0(29); lwzx 3,28,9; lwz 11,0x4c(3); lwz 0,0x18(11); cmpwi 0,0; bne 4f; li 4,1; bl _s80283E6C_2; b 4f; 2:; lwz 9,0x0(29); li 30,0; lwzx 31,28,9; mr 3,31; bl _s80283E6C_3; cmpwi 3,13; bne 3f; mr 3,31; bl _s80283E6C_4; subfic 0,3,0; adde 30,0,3; 3:; cmpwi 30,0; beq 4f; lwz 9,0x0(29); lwzx 3,28,9; lwz 11,0x4c(3); lwz 0,0x18(11); cmpwi 0,-1; bne 4f; bl _s80283E6C_5; 4:; lwz 9,0x0(29); lis 5,-32704; addi 5,5,11876; addi 4,26,12028; lwzx 11,28,9; li 6,945; addi 27,27,1; addi 28,28,4; lwz 9,0x8(11); lwz 0,0x14(9); lha 3,0x10(9); mtspr 8,0; add 3,11,3; blrl; lwz 0,0x4(29); cmpw 27,0; blt 0b; 5:; li 0,0; stw 0,0x4(29); lwz 0,0x24(1); mtspr 8,0; lmw 26,0x8(1); addi 1,1,32"
extern "C" void _s80283E6C_0();
extern "C" void _s80283E6C_1();
extern "C" void _s80283E6C_2();
extern "C" void _s80283E6C_3();
extern "C" void _s80283E6C_4();
extern "C" void _s80283E6C_5();
extern "C" void f_80283E6C() {}
