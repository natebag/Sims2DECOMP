// 0x80099C44 WorldMap::Reset(void) (444 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-136(1); mfspr 0,8; stmw 30,0x80(1); stw 0,0x8c(1); mr 30,3; lwz 11,-26512(13); lwz 0,0x8(30); li 6,0; stw 6,0x0(30); addi 7,13,-32144; stw 0,0x30(11); lis 9,-32706; lfs f11,-29588(9); lis 8,-32706; lwz 11,0x8(30); lis 9,-32706; lfs f12,-29580(9); addi 10,1,8; addis 11,11,3; lis 9,-32706; stw 7,-7084(11); lis 5,-32706; lfs f13,-29576(9); lis 3,-32706; lwz 11,0x8(30); li 4,1; lfs f0,-29584(8); addis 11,11,3; lis 8,-32706; stw 6,-7080(11); lfs f10,-29572(8); lwz 9,0x8(30); addis 9,9,3; stfs f11,-7076(9); stfs f0,0x8(1); stfs f0,0x4(10); stfs f12,0x8(10); lwz 7,0x4(10); lwz 9,0x8(30); lwz 8,0x8(1); lwz 0,0x8(10); addis 9,9,3; stw 8,-7268(9); addi 11,9,-7268; stw 7,0x4(11); addi 6,9,-7296; stw 0,0x8(11); stfs f13,0x8(1); stfs f13,0x4(10); stfs f13,0x8(10); lwz 8,0x4(10); lwz 0,0x8(1); lwz 11,0x8(10); stw 0,-7296(9); stw 11,0x8(6); stw 8,0x4(6); stfs f10,-7300(9); lfs f0,-29568(5); lwz 11,0x8(30); stfs f0,0x8(1); stfs f0,0x4(10); addis 11,11,3; stfs f13,0x8(10); addi 8,11,-7112; lwz 7,0x4(10); lwz 0,0x8(1); lwz 9,0x8(10); stw 0,-7112(11); lfs f0,-29564(3); stw 9,0x8(8); stw 7,0x4(8); stfs f0,-7116(11); lwz 9,0x8(30); stfs f13,0x14(9); lwz 3,0x8(30); bl _s80099C44_0; lfs f1,0xbc(30); addi 4,1,24; lwz 3,0x8(30); bl _s80099C44_1; lwz 3,0x8(30); bl _s80099C44_2; lwz 3,0x8(30); bl _s80099C44_3; lwz 3,0x8(30); bl _s80099C44_4; lis 9,-32697; addi 3,9,24012; lwz 31,0x118(3); cmpwi 31,0; beq 0f; mr 4,31; bl _s80099C44_5; lwz 4,0x4(30); mr 3,31; li 5,1; bl _s80099C44_6; lwz 0,0x240(31); lis 4,-17796; mr 3,31; ori 4,4,240; rlwinm 0,0,0,0,30; li 5,0; stw 0,0x240(31); li 6,0; bl _s80099C44_7; 0:; lwz 0,0x8c(1); mtspr 8,0; lmw 30,0x80(1); addi 1,1,136"
extern "C" void _s80099C44_0();
extern "C" void _s80099C44_1();
extern "C" void _s80099C44_2();
extern "C" void _s80099C44_3();
extern "C" void _s80099C44_4();
extern "C" void _s80099C44_5();
extern "C" void _s80099C44_6();
extern "C" void _s80099C44_7();
extern "C" void f_80099C44() {}
