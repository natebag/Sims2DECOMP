// 0x80267200 AISetStreamSampleRate (40 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; cmplwi 3,1; stw 0,0x4(1); stwu 1,-8(1); bne 0f; bl _s80267200_0; 0:; lwz 0,0xc(1); addi 1,1,8; mtspr 8,0"
extern "C" void _s80267200_0();
extern "C" void f_80267200() {}
