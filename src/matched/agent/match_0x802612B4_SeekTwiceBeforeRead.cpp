// 0x802612B4 SeekTwiceBeforeRead (128 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; lis 7,-32694; stw 0,0x4(1); rlwinm. 8,5,0,0,16; addi 9,7,-16952; stwu 1,-8(1); bne 0f; li 10,0; b 1f; 0:; lwz 0,-23320(13); add 10,8,0; 1:; li 0,2; stw 0,0x0(9); li 8,1; li 7,-1; stw 10,0xc(9); li 0,0; stw 6,0x10(9); stw 8,0x14(9); stw 3,0x18(9); mr 3,10; stw 4,0x1c(9); mr 4,6; stw 5,0x20(9); stw 6,0x24(9); stw 7,0x28(9); stw 0,-23292(13); bl _s802612B4_0; lwz 0,0xc(1); addi 1,1,8; mtspr 8,0"
extern "C" void _s802612B4_0();
extern "C" void f_802612B4() {}
