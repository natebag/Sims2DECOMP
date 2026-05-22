// 0x8039B230 __VMBASEInitPageTable (60 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 0,0x14(1); bl _s8039B230_0; rlwinm 4,3,0,16,31; addis 0,3,1; subf 3,4,0; stw 3,-21536(13); addis 3,3,1; bl _s8039B230_1; bl _s8039B230_2; lwz 0,0x14(1); mtspr 8,0; addi 1,1,16"
extern "C" void _s8039B230_0();
extern "C" void _s8039B230_1();
extern "C" void _s8039B230_2();
extern "C" void f_8039B230() {}
