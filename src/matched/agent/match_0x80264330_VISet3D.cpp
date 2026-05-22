// 0x80264330 VISet3D (256 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; lis 4,-32694; stw 0,0x4(1); stwu 1,-32(1); stw 31,0x1c(1); addi 31,4,-16744; stw 30,0x18(1); addi 30,3,0; bl _s80264330_0; stw 30,0x134(31); lis 0,16384; lwz 7,0x134(31); lhz 5,0x2(31); rlwinm 4,7,3,0,28; rlwinm 5,5,0,29,27; or 4,5,4; sth 4,0x2(31); cmpwi 7,0; lwz 4,-23240(13); lwz 5,-23236(13); or 0,4,0; stw 5,-23236(13); stw 0,-23240(13); lhz 5,0xf4(31); lhz 0,0x10a(31); beq 0f; rlwinm 0,0,1,0,30; 0:; rlwinm 6,0,0,16,31; cmplw 6,5; bge 1f; rlwinm 4,6,8,0,23; addi 0,4,-1; add 0,5,0; divwu 0,0,5; ori 0,0,4096; sth 0,0x4a(31); lis 0,1024; lwz 4,-23240(13); lwz 5,-23236(13); or 0,5,0; stw 0,-23236(13); stw 4,-23240(13); sth 6,0x70(31); lwz 4,-23240(13); lwz 0,-23236(13); ori 0,0,128; stw 0,-23236(13); stw 4,-23240(13); b 2f; 1:; li 0,256; sth 0,0x4a(31); lis 0,1024; lwz 4,-23240(13); lwz 5,-23236(13); or 0,5,0; stw 0,-23236(13); stw 4,-23240(13); 2:; bl _s80264330_1; lwz 0,0x24(1); lwz 31,0x1c(1); lwz 30,0x18(1); addi 1,1,32; mtspr 8,0"
extern "C" void _s80264330_0();
extern "C" void _s80264330_1();
extern "C" void f_80264330() {}
