// 0x802EE17C EAnimController::SetTrackBlend(EACTrack (96 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); mr. 4,4; beq 1f; lwz 0,0xa8(4); cmpwi 0,1; bne 1f; lbz 0,0xe(4); cmpwi 0,0; bne 0f; li 5,1; bl _s802EE17C_0; b 1f; 0:; blt 1f; cmpwi 0,2; bgt 1f; lfs f2,0x1c(4); lfs f3,0x20(4); bl _s802EE17C_1; 1:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s802EE17C_0();
extern "C" void _s802EE17C_1();
extern "C" void f_802EE17C() {}
