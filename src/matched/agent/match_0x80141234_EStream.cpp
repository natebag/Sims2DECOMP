// 0x80141234 EStream (240 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="cmpwi 3,0; bne 0f; li 3,189; li 4,0; bl _s80141234_0; 0:; lhz 0,0x36(31); lis 9,-32706; lfs f0,-10652(9); ori 0,0,1; stfs f0,0xa8(31); sth 0,0x36(31); lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16; blr; stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lwz 9,0x0(31); lha 3,0x60(9); lwz 0,0x64(9); add 3,31,3; mtspr 8,0; blrl; cmpwi 3,0; beq 1f; li 3,189; li 4,0; bl _s80141234_1; lis 9,-32706; lfs f0,-10648(9); stfs f0,0xa0(31); 1:; lhz 0,0x36(31); mr 3,31; rlwinm 0,0,0,0,30; sth 0,0x36(31); bl _s80141234_2; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16; blr; stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 9,0x0(3); lha 0,0x70(9); lwz 9,0x74(9); add 3,3,0; mtspr 8,9; blrl; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8; blr; lwz 3,0x9c(3)"
extern "C" void _s80141234_0();
extern "C" void _s80141234_1();
extern "C" void _s80141234_2();
extern "C" void f_80141234() {}
