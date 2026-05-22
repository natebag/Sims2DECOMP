// 0x803A7D70 FileList::FileList(void) (104 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 29,0x1c(1); stw 0,0x2c(1); mr 30,3; li 29,0; stw 29,0x4(30); li 3,28; bl _s803A7D70_0; mr 9,3; stw 29,0x8(30); stw 9,0x4(30); mr 3,30; stb 29,0xc(30); stw 29,0x0(9); lwz 11,0x4(30); stw 29,0x4(11); lwz 9,0x4(30); stw 9,0x8(9); lwz 11,0x4(30); stw 11,0xc(11); lwz 0,0x2c(1); mtspr 8,0; lmw 29,0x1c(1); addi 1,1,40"
extern "C" void _s803A7D70_0();
extern "C" void f_803A7D70() {}
