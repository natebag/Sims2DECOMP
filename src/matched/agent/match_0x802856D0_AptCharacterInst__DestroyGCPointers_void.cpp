// 0x802856D0 AptCharacterInst::DestroyGCPointers(void) (64 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lwz 3,0xc(31); cmpwi 3,0; beq 0f; bl _s802856D0_0; 0:; li 0,1; stw 0,0x10(31); lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s802856D0_0();
extern "C" void f_802856D0() {}
