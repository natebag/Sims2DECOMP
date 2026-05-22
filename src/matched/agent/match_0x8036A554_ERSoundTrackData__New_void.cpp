// 0x8036A554 ERSoundTrackData::New(void) (48 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); bl _s8036A554_0; li 4,36; li 5,0; bl _s8036A554_1; bl _s8036A554_2; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s8036A554_0();
extern "C" void _s8036A554_1();
extern "C" void _s8036A554_2();
extern "C" void f_8036A554() {}
