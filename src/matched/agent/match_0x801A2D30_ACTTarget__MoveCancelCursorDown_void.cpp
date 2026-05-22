// 0x801A2D30 ACTTarget::MoveCancelCursorDown(void) (72 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); mr 11,3; lwz 9,0x648(11); cmpwi 9,0; beq 0f; lwz 0,0x48(9); cmpwi 0,0; beq 0f; stw 9,0x64c(11); lwz 0,0x48(9); stw 0,0x648(11); bl _s801A2D30_0; 0:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s801A2D30_0();
extern "C" void f_801A2D30() {}
