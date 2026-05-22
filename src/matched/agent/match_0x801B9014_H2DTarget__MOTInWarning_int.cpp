// 0x801B9014 H2DTarget::MOTInWarning(int, (60 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); rlwinm 4,4,2,0,29; addi 3,3,136; lwzx 3,3,4; cmpwi 3,0; beq 0f; li 4,3; li 6,0; bl _s801B9014_0; 0:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s801B9014_0();
extern "C" void f_801B9014() {}
