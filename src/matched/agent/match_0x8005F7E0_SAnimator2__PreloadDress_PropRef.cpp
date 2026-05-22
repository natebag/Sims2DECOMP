// 0x8005F7E0 SAnimator2::PreloadDress(PropRef (76 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); bl _s8005F7E0_0; mr. 4,3; beq 0f; lis 3,-32692; addi 3,3,-27556; bl _s8005F7E0_1; cmpwi 3,0; li 3,0; beq 1f; li 3,1; b 1f; 0:; li 3,0; 1:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s8005F7E0_0();
extern "C" void _s8005F7E0_1();
extern "C" void f_8005F7E0() {}
