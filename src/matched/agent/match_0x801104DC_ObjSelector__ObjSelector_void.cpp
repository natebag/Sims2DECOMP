// 0x801104DC ObjSelector::ObjSelector(void) (196 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 30,3; li 29,0; li 28,-1; stw 29,0xc(30); stw 28,0x4(30); addi 3,30,28; stw 28,0x8(30); stw 29,0x10(30); bl _s801104DC_0; stw 29,0x3c(30); addi 9,30,88; stw 29,0x50(30); lis 0,-1; stw 29,0x54(30); mr 3,30; stw 29,0x58(30); stw 29,0x4(9); stw 28,0x78(30); stw 0,0x7c(30); stw 29,0x4c(30); stw 29,0x60(30); stw 29,0x64(30); stw 29,0x68(30); sth 29,0x6c(30); stw 28,0x70(30); stw 28,0x74(30); stw 29,0x80(30); stw 29,0x84(30); stw 29,0x88(30); stw 29,0x8c(30); stw 29,0x90(30); stw 29,0x94(30); stw 29,0x98(30); stw 29,0x9c(30); stw 29,0xa0(30); stw 29,0xa4(30); stw 29,0x0(30); stw 29,0x40(30); stw 29,0x44(30); stw 29,0x48(30); lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s801104DC_0();
extern "C" void f_801104DC() {}
