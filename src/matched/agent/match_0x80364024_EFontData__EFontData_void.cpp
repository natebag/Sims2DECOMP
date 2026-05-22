// 0x80364024 EFontData::EFontData(void) (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); lis 9,-32697; mr 30,3; addi 9,9,-10016; li 29,0; stw 9,0x0(30); addi 11,30,4; stw 29,0x4(11); li 0,1; stw 29,0x4(30); addi 3,30,40; stw 0,0x8(11); li 4,237; bl _s80364024_0; stw 29,0x24(30); mr 3,30; stw 29,0x10(30); stw 29,0x14(30); stw 29,0x1c(30); stw 29,0x18(30); stw 29,0x20(30); lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s80364024_0();
extern "C" void f_80364024() {}
