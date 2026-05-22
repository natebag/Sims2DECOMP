// 0x8024BAA8 __OSDBIntegrator (36 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 5,64; mfspr 3,8; stw 3,0xc(5); lwz 3,0x8(5); oris 3,3,32768; mtspr 8,3; li 3,48; mtmsr 3"
extern "C" void f_8024BAA8() {}
