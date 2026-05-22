// 0x802F6580 ERC::Init(RCMode) (136 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; mr 0,4; lwz 3,-26392(13); stw 0,0xc(30); bl _s802F6580_0; stw 3,0x0(30); li 4,4096; mr 3,30; li 5,32; bl _s802F6580_1; lwz 9,0x20(30); li 11,0; lwz 8,0x0(30); li 10,512; addi 9,9,1; li 0,-1; stw 9,0x20(30); stw 3,0x48(8); stw 0,0x44(30); stw 10,0x4(30); stw 3,0x8(30); stw 11,0x1c(30); stw 11,0x14(30); stw 11,0x10(30); stb 11,0x18(30); lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s802F6580_0();
extern "C" void _s802F6580_1();
extern "C" void f_802F6580() {}
