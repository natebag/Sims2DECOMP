// 0x80369DE0 ERSoundEvent::Refresh(EFile (40 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); mr. 4,4; beq 0f; bl _s80369DE0_0; 0:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s80369DE0_0();
extern "C" void f_80369DE0() {}
