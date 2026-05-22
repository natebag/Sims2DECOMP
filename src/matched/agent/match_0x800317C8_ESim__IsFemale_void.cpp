// 0x800317C8 ESim::IsFemale(void) (36 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); bl _s800317C8_0; xori 3,3,1; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s800317C8_0();
extern "C" void f_800317C8() {}
