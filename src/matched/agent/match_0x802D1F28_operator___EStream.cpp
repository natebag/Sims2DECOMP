// 0x802D1F28 operator<<(EStream (260 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); mr 31,3; mr. 30,4; beq 2f; lwz 0,0x0(31); cmpwi 0,0; beq 1f; lwz 9,0x18(31); lwz 0,0x2c(9); lha 3,0x28(9); mtspr 8,0; add 3,31,3; blrl; mr 4,3; lwz 3,0x4(31); bl _s802D1F28_0; lwz 9,0x18(31); addi 4,1,8; stw 30,0x8(1); li 5,4; lha 3,0x38(9); lwz 0,0x3c(9); add 3,31,3; mtspr 8,0; blrl; lwz 3,0x10(31); mr 4,30; li 5,-1; li 6,0; bl _s802D1F28_1; cmpwi 3,0; beq 3f; lwz 4,0xc(31); cmpwi 4,0; beq 0f; lwz 3,0x8(31); mr 5,30; bl _s802D1F28_2; b 3f; 0:; lwz 3,0x8(31); mr 4,30; bl _s802D1F28_3; b 3f; 1:; mr 4,30; mr 3,31; bl _s802D1F28_4; b 3f; 2:; lwz 9,0x18(31); addi 4,1,12; stw 30,0xc(1); li 5,4; lha 3,0x38(9); lwz 0,0x3c(9); add 3,31,3; mtspr 8,0; blrl; 3:; mr 3,31; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"
extern "C" void _s802D1F28_0();
extern "C" void _s802D1F28_1();
extern "C" void _s802D1F28_2();
extern "C" void _s802D1F28_3();
extern "C" void _s802D1F28_4();
extern "C" void f_802D1F28() {}
