// 0x80380040 __CARDWritePage (316 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-24(1); stw 31,0x14(1); stw 30,0x10(1); addi 30,3,0; mulli 5,30,272; lis 3,-32688; addi 0,3,-24000; add 31,0,5; li 0,242; stb 0,0x94(31); lhz 0,0xa(31); cmplwi 0,128; ble 0f; lwz 0,0xb0(31); rlwinm 0,0,15,25,31; ori 0,0,128; stb 0,0x95(31); b 1f; 0:; lwz 0,0xb0(31); rlwinm 0,0,15,25,31; stb 0,0x95(31); 1:; lwz 0,0xb0(31); li 7,5; li 6,1; rlwinm 0,0,23,24,31; stb 0,0x96(31); li 0,3; addi 3,30,0; lwz 8,0xb0(31); addi 5,4,0; li 4,0; rlwinm 8,8,25,30,31; stb 8,0x97(31); lwz 8,0xb0(31); rlwinm 8,8,0,25,31; stb 8,0x98(31); stw 7,0xa0(31); stw 6,0xa4(31); stw 0,0xa8(31); bl _s80380040_0; cmpwi 3,-1; bne 2f; li 3,0; b 5f; 2:; cmpwi 3,0; blt 5f; lwz 5,0xa0(31); addi 3,30,0; addi 4,31,148; li 6,1; bl _s80380040_1; cmpwi 3,0; beq 3f; lis 3,-32712; lwz 4,0xb4(31); addi 7,3,-3752; lhz 5,0xa(31); lwz 6,0xa4(31); mr 3,30; bl _s80380040_2; cmpwi 3,0; bne 4f; 3:; li 0,0; stw 0,0xcc(31); mr 3,30; bl _s80380040_3; mr 3,30; bl _s80380040_4; li 3,-3; b 5f; 4:; li 3,0; 5:; lwz 0,0x1c(1); lwz 31,0x14(1); lwz 30,0x10(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s80380040_0();
extern "C" void _s80380040_1();
extern "C" void _s80380040_2();
extern "C" void _s80380040_3();
extern "C" void _s80380040_4();
extern "C" void f_80380040() {}
