// 0x80319FD0 ERModel::RegisterMorphTarget(int, (112 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; mr 29,5; lis 3,-32692; li 5,0; addi 3,3,-27556; li 6,0; bl _s80319FD0_0; mr. 31,3; li 3,0; beq 0f; mr 3,30; mr 5,29; mr 4,31; bl _s80319FD0_1; cmpwi 3,0; mr 3,31; bne 0f; bl _s80319FD0_2; li 3,0; 0:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s80319FD0_0();
extern "C" void _s80319FD0_1();
extern "C" void _s80319FD0_2();
extern "C" void f_80319FD0() {}
