// 0x801A2CDC ACTTarget::MoveCancelCursorUp(void) (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); mr 10,3; lwz 9,0x648(10); cmpwi 9,0; beq 0f; lwz 11,0x44(9); cmpwi 11,0; beq 0f; lwz 0,0x0(11); cmpwi 0,8; bgt 0f; stw 9,0x64c(10); lwz 0,0x44(9); stw 0,0x648(10); bl _s801A2CDC_0; 0:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s801A2CDC_0();
extern "C" void f_801A2CDC() {}
