// 0x80169A40 CasSimDescriptionS2C::SwitchInnerLayerTorso(bool) (28 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr. 4,4; beq 0f; li 0,1; stw 0,0x9c(3); blr; 0:; stw 4,0x9c(3)"
extern "C" void f_80169A40() {}
