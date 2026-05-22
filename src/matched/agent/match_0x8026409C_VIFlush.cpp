// 0x8026409C VIFlush (304 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; lis 3,-32694; stw 0,0x4(1); stwu 1,-32(1); stw 31,0x1c(1); addi 31,3,-16744; stw 30,0x18(1); stw 29,0x14(1); stw 28,0x10(1); bl _s8026409C_0; lwz 5,-23232(13); addi 30,3,0; li 0,0; lwz 4,-23248(13); or 3,5,4; stw 3,-23232(13); stw 0,-23248(13); lwz 4,-23224(13); lwz 5,-23220(13); lwz 0,-23240(13); lwz 3,-23236(13); or 0,4,0; or 3,5,3; stw 3,-23220(13); stw 0,-23224(13); b 3f; 0:; lwz 3,-23240(13); li 5,32; lwz 28,-23236(13); addi 4,28,0; bl _s8026409C_1; cntlzw 4,4; cmpwi 4,32; li 0,-1; and 0,28,0; bge 1f; b 2f; 1:; cntlzw 3,0; addi 4,3,32; 2:; rlwinm 3,4,1,0,30; lhzx 0,31,3; add 3,31,3; subfic 5,4,63; sth 0,0x78(3); li 3,0; li 4,1; bl _s8026409C_2; lwz 0,-23240(13); not 5,3; not 4,4; lwz 3,-23236(13); and 0,0,5; and 3,3,4; stw 3,-23236(13); stw 0,-23240(13); 3:; lwz 0,-23240(13); li 3,0; lwz 4,-23236(13); xor 0,0,3; xor 3,4,3; or. 0,3,0; bne 0b; li 0,1; stw 0,-23280(13); mr 3,30; lwz 0,0x120(31); stw 0,-23208(13); bl _s8026409C_3; lwz 0,0x24(1); lwz 31,0x1c(1); lwz 30,0x18(1); lwz 29,0x14(1); lwz 28,0x10(1); addi 1,1,32; mtspr 8,0"
extern "C" void _s8026409C_0();
extern "C" void _s8026409C_1();
extern "C" void _s8026409C_2();
extern "C" void _s8026409C_3();
extern "C" void f_8026409C() {}
