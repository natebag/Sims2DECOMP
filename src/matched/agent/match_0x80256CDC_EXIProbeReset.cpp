// 0x80256CDC EXIProbeReset (76 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-8(1); li 0,0; lis 4,-32768; stw 0,0x30c4(4); stw 0,0x30c0(4); lis 3,-32694; addi 3,3,-22064; stw 0,0x60(3); stw 0,0x20(3); li 3,0; bl _s80256CDC_0; li 3,1; bl _s80256CDC_1; lwz 0,0xc(1); addi 1,1,8; mtspr 8,0"
extern "C" void _s80256CDC_0();
extern "C" void _s80256CDC_1();
extern "C" void f_80256CDC() {}
