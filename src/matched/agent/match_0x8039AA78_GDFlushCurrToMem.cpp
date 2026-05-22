// 0x8039AA78 GDFlushCurrToMem (44 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-8(1); lwz 4,-21544(13); lwz 3,0x0(4); lwz 4,0x4(4); bl _s8039AA78_0; lwz 0,0xc(1); addi 1,1,8; mtspr 8,0"
extern "C" void _s8039AA78_0();
extern "C" void f_8039AA78() {}
