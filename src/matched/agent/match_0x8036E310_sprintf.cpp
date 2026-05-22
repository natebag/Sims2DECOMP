// 0x8036E310 sprintf (216 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-248(1); mfspr 0,8; stw 31,0xf4(1); stw 0,0xfc(1); lis 31,512; addi 0,1,256; addi 11,1,8; stw 0,0xe4(1); stw 11,0xe8(1); mr 12,3; stw 5,0x10(1); stw 6,0x14(1); stw 7,0x18(1); stw 8,0x1c(1); stw 9,0x20(1); stw 10,0x24(1); stw 31,0xe0(1); bne cr1,0f; stfd f1,0x28(1); stfd f2,0x30(1); stfd f3,0x38(1); stfd f4,0x40(1); stfd f5,0x48(1); stfd f6,0x50(1); stfd f7,0x58(1); stfd f8,0x60(1); 0:; lwz 10,-27948(13); lis 9,32767; ori 9,9,65535; li 0,520; stw 9,0x94(1); addi 8,1,224; stw 9,0x88(1); addi 11,1,112; sth 0,0x8c(1); mr 5,11; stw 12,0x90(1); addi 3,1,128; stw 10,0xdc(1); stw 12,0x80(1); lwz 0,0x4(8); lwz 10,0x8(8); stw 31,0x70(1); stw 0,0x4(11); stw 10,0x8(11); bl _s8036E310_0; lwz 9,0x80(1); li 0,0; stb 0,0x0(9); lwz 0,0xfc(1); mtspr 8,0; lwz 31,0xf4(1); addi 1,1,248"
extern "C" void _s8036E310_0();
extern "C" void f_8036E310() {}
