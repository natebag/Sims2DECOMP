// 0x80267DCC DBInitComm (120 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-32(1); stw 31,0x1c(1); stw 30,0x18(1); addi 30,4,0; stw 29,0x14(1); addi 29,3,0; bl _s80267DCC_0; addi 0,13,-23036; stw 0,-23040(13); lis 4,2; addi 31,3,0; lwz 0,-23040(13); addi 3,4,-32768; stw 0,0x0(29); stw 30,-23056(13); bl _s80267DCC_1; lis 3,-13312; li 0,0; stw 0,0x6828(3); mr 3,31; bl _s80267DCC_2; lwz 0,0x24(1); lwz 31,0x1c(1); lwz 30,0x18(1); lwz 29,0x14(1); addi 1,1,32; mtspr 8,0"
extern "C" void _s80267DCC_0();
extern "C" void _s80267DCC_1();
extern "C" void _s80267DCC_2();
extern "C" void f_80267DCC() {}
