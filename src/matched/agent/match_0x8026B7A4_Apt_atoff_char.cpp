// 0x8026B7A4 Apt_atoff(char (36 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); bl _s8026B7A4_0; frsp f1,f1; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s8026B7A4_0();
extern "C" void f_8026B7A4() {}
