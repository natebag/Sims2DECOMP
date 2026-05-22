// 0x802654C4 PADProbeCallback (216 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); rlwinm. 0,4,0,28,31; stwu 1,-48(1); stw 31,0x2c(1); stw 30,0x28(1); bne 0f; lwz 30,-27652(13); lis 31,-32768; lwz 3,-23180(13); addi 4,1,28; srw 0,31,30; or 0,3,0; stw 0,-23180(13); mr 3,30; bl _s802654C4_0; lwz 0,-27644(13); addi 3,30,0; oris 4,0,64; bl _s802654C4_1; lwz 3,-23180(13); bl _s802654C4_2; lwz 0,-27652(13); lwz 3,-23168(13); srw 0,31,0; or 0,3,0; stw 0,-23168(13); 0:; lwz 5,-23176(13); cntlzw 0,5; stw 0,-27652(13); lwz 4,-27652(13); cmpwi 4,32; beq 1f; lis 0,-32768; srw 0,0,4; andc 0,5,0; mulli 4,4,12; stw 0,-23176(13); lis 3,-32694; addi 0,3,-16400; add 3,0,4; li 4,0; li 5,12; bl _s802654C4_3; lis 4,-32730; lwz 3,-27652(13); addi 4,4,21916; bl _s802654C4_4; 1:; lwz 0,0x34(1); lwz 31,0x2c(1); lwz 30,0x28(1); addi 1,1,48; mtspr 8,0"
extern "C" void _s802654C4_0();
extern "C" void _s802654C4_1();
extern "C" void _s802654C4_2();
extern "C" void _s802654C4_3();
extern "C" void _s802654C4_4();
extern "C" void f_802654C4() {}
