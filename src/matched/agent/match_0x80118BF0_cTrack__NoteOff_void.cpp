// 0x80118BF0 cTrack::NoteOff(void) (52 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 0,0x50(3); li 3,1; cmpwi 0,0; beq 0f; mr 3,0; bl _s80118BF0_0; 0:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s80118BF0_0();
extern "C" void f_80118BF0() {}
