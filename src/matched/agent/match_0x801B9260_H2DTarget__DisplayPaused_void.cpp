// 0x801B9260 H2DTarget::DisplayPaused(void) (44 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 3,0x88(3); cmpwi 3,0; beq 0f; bl _s801B9260_0; 0:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s801B9260_0();
extern "C" void f_801B9260() {}
