// 0x800AC90C ResourceBehavior::Init(Language (220 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,5; mr 31,3; bl _s800AC90C_0; lwz 9,0x54(30); lwz 4,0xc(9); cmpwi 4,0; beq 0f; lis 3,-32693; li 5,0; addi 3,3,27900; li 6,0; bl _s800AC90C_1; stw 3,0x10(31); b 1f; 0:; stw 4,0x10(31); 1:; lwz 9,0x54(30); lwz 5,0x34(9); cmpwi 5,0; beq 2f; lwz 4,0xc(5); lis 3,-32693; addi 3,3,27900; li 5,0; li 6,0; bl _s800AC90C_2; stw 3,0x14(31); 2:; lwz 29,-21508(13); mr 3,31; lwz 30,0x0(29); lha 0,0x38(30); addi 30,30,56; add 29,29,0; bl _s800AC90C_3; lwz 0,0x4(30); mr 4,3; mr 3,29; mtspr 8,0; blrl; lwz 9,0x8(3); li 5,0; lis 3,-32693; li 6,0; lwz 4,0xc(9); addi 3,3,27900; bl _s800AC90C_4; stw 3,0x18(31); lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s800AC90C_0();
extern "C" void _s800AC90C_1();
extern "C" void _s800AC90C_2();
extern "C" void _s800AC90C_3();
extern "C" void _s800AC90C_4();
extern "C" void f_800AC90C() {}
