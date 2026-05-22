// 0x8005F758 SAnimator2::RemoveProp(unsigned (136 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; rlwinm 29,4,2,0,29; lwz 9,0x168(30); lis 3,-32692; addi 3,3,-27556; addi 31,30,360; lwzx 11,9,29; lwz 4,0x0(11); bl _s8005F758_0; lwz 9,0x168(30); lwzx 3,9,29; bl _s8005F758_1; lwz 0,0x168(30); lwz 5,0x4(31); add 3,29,0; addi 4,3,4; cmpw 4,5; beq 0f; cmpw 5,4; beq 0f; subf 5,4,5; bl _s8005F758_2; 0:; lwz 9,0x4(31); addi 9,9,-4; stw 9,0x4(31); lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8005F758_0();
extern "C" void _s8005F758_1();
extern "C" void _s8005F758_2();
extern "C" void f_8005F758() {}
