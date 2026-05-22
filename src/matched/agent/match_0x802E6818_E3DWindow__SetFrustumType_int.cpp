// 0x802E6818 E3DWindow::SetFrustumType(int) (48 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 0,0x31c(3); cmpw 0,4; beq 0f; stw 4,0x31c(3); bl _s802E6818_0; 0:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s802E6818_0();
extern "C" void f_802E6818() {}
