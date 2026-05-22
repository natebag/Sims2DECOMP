// 0x8024E8C8 __OSGetExecParams (64 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-8(1); lis 5,-32768; lwz 4,0x30f0(5); cmplw 5,4; bgt 0f; li 5,28; bl _s8024E8C8_0; b 1f; 0:; li 0,0; stw 0,0x0(3); 1:; lwz 0,0xc(1); addi 1,1,8; mtspr 8,0"
extern "C" void _s8024E8C8_0();
extern "C" void f_8024E8C8() {}
