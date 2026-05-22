// 0x80392214 VMResizeARAM (40 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 0,0x14(1); stw 3,-25224(13); stw 4,-21888(13); bl _s80392214_0; lwz 0,0x14(1); mtspr 8,0; addi 1,1,16"
extern "C" void _s80392214_0();
extern "C" void f_80392214() {}
