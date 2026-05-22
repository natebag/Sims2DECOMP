// 0x80252788 __OSReadROMCallback (92 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-24(1); stw 31,0x14(1); mr 31,3; bl _s80252788_0; mr 3,31; bl _s80252788_1; lis 3,-32694; addi 3,3,-24704; lwzu 0,0x50(3); cmplwi 0,0; mr 12,0; beq 0f; li 0,0; mtspr 8,12; stw 0,0x0(3); blrl; 0:; lwz 0,0x1c(1); lwz 31,0x14(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s80252788_0();
extern "C" void _s80252788_1();
extern "C" void f_80252788() {}
