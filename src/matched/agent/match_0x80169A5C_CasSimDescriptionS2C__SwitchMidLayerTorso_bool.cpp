// 0x80169A5C CasSimDescriptionS2C::SwitchMidLayerTorso(bool) (156 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr. 4,4; beq 4f; lwz 0,0xa8(3); cmpwi 0,1; beq 2f; bgt 0f; cmpwi 0,0; beq 1f; blr; 0:; cmpwi 0,2; beq 3f; blr; 1:; li 0,3; stw 0,0xa8(3); blr; 2:; li 0,4; stw 0,0xa8(3); blr; 3:; li 0,5; stw 0,0xa8(3); blr; 4:; lwz 0,0xa8(3); cmpwi 0,4; beq 7f; bgt 5f; cmpwi 0,3; beq 6f; blr; 5:; cmpwi 0,5; beq 8f; blr; 6:; stw 4,0xa8(3); blr; 7:; li 0,1; stw 0,0xa8(3); blr; 8:; li 0,2; stw 0,0xa8(3)"
extern "C" void f_80169A5C() {}
