// 0x8029D004 AptAnimationPoolData::setValidFocusButton(void) (412 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 24,0x10(1); stw 0,0x34(1); mr 31,3; lwz 3,0x64(31); cmpwi 3,0; beq 0f; addi 3,3,12; addi 4,1,8; addi 5,1,12; bl _s8029D004_0; cmpwi 3,0; bne 5f; lwz 3,0x64(31); cmpwi 3,0; beq 0f; li 4,1; bl _s8029D004_1; lwz 4,0x64(31); mr 3,31; li 5,2; bl _s8029D004_2; lwz 11,0x64(31); cmpwi 11,0; beq 0f; lwz 9,0x8(11); lis 4,-32703; lis 5,-32703; addi 4,4,-30332; lha 3,0x10(9); addi 5,5,-30280; lwz 0,0x14(9); li 6,360; add 3,11,3; mtspr 8,0; blrl; 0:; li 0,0; addi 9,31,8; stw 0,0x64(31); li 29,0; mr 27,9; li 28,0; lhz 0,0x2(9); cmpw 29,0; bge 4f; lhz 0,0x8(31); cmpw 29,0; beq 4f; lis 9,-32700; lis 24,-32703; addi 26,9,-6476; lis 25,-32703; li 30,0; 1:; lwz 9,0xc(31); lwzx 3,30,9; cmpwi 3,0; beq 3f; lwz 0,0xc(3); addi 3,3,12; cmpw 0,26; beq 2f; addi 4,1,8; addi 5,1,12; bl _s8029D004_3; cmpwi 3,0; beq 2f; lwz 9,0xc(31); addi 4,24,-30332; addi 5,25,-30280; li 6,377; lwzx 3,30,9; stw 3,0x64(31); lwz 9,0x8(3); lha 0,0x8(9); lwz 9,0xc(9); add 3,3,0; mtspr 8,9; blrl; b 4f; 2:; addi 29,29,1; 3:; lhz 0,0x2(27); addi 28,28,1; addi 30,30,4; cmpw 28,0; bge 4f; lhz 0,0x8(31); cmpw 29,0; bne 1b; 4:; lwz 3,0x64(31); cmpwi 3,0; beq 5f; li 4,2; bl _s8029D004_4; mr 3,31; li 5,1; lwz 4,0x64(3); bl _s8029D004_5; 5:; lwz 0,0x34(1); mtspr 8,0; lmw 24,0x10(1); addi 1,1,48"
extern "C" void _s8029D004_0();
extern "C" void _s8029D004_1();
extern "C" void _s8029D004_2();
extern "C" void _s8029D004_3();
extern "C" void _s8029D004_4();
extern "C" void _s8029D004_5();
extern "C" void f_8029D004() {}
