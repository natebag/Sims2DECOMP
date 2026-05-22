// 0x8006C850 SAnimator2::StartAutoRun(float) (112 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; addi 3,31,1568; bl _s8006C850_0; cmpwi 3,1; stw 3,0x600(31); beq 0f; li 3,0; b 1f; 0:; lwz 10,0x4(31); li 4,17; li 5,1; lwz 11,0x0(10); lwz 9,0x4(11); lha 3,0x1e8(9); lwz 0,0x1ec(9); add 3,11,3; mtspr 8,0; blrl; li 3,1; 1:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s8006C850_0();
extern "C" void f_8006C850() {}
