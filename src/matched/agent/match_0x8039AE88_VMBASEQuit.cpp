// 0x8039AE88 VMBASEQuit (88 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 0,0x14(1); stw 31,0xc(1); bl _s8039AE88_0; mr 31,3; bl _s8039AE88_1; bl _s8039AE88_2; bl _s8039AE88_3; li 0,0; mr 3,31; stw 0,-21536(13); stw 0,-21532(13); stw 0,-21528(13); stw 0,-21524(13); stw 0,-21520(13); bl _s8039AE88_4; lwz 0,0x14(1); lwz 31,0xc(1); mtspr 8,0; addi 1,1,16"
extern "C" void _s8039AE88_0();
extern "C" void _s8039AE88_1();
extern "C" void _s8039AE88_2();
extern "C" void _s8039AE88_3();
extern "C" void _s8039AE88_4();
extern "C" void f_8039AE88() {}
