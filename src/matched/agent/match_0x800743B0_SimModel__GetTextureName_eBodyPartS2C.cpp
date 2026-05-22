// 0x800743B0 SimModel::GetTextureName(eBodyPartS2C, (180 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,5; li 6,0; lwz 5,0x13c(3); lwz 3,0x138(3); bl _s800743B0_0; mr. 31,3; bne 0f; lis 4,-32707; mr 3,30; addi 4,4,22056; bl _s800743B0_1; b 1f; 0:; lis 4,-32707; mr 3,30; addi 4,4,22064; lis 29,-32692; bl _s800743B0_2; addi 3,29,-7364; mr 4,31; bl _s800743B0_3; cmpwi 3,0; beq 1f; mr 4,31; addi 3,29,-7364; li 5,0; li 6,0; bl _s800743B0_4; mr. 31,3; beq 1f; lis 4,-32707; mr 3,30; addi 4,4,21620; bl _s800743B0_5; mr 3,31; bl _s800743B0_6; 1:; lwz 3,0x0(30); lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s800743B0_0();
extern "C" void _s800743B0_1();
extern "C" void _s800743B0_2();
extern "C" void _s800743B0_3();
extern "C" void _s800743B0_4();
extern "C" void _s800743B0_5();
extern "C" void _s800743B0_6();
extern "C" void f_800743B0() {}
