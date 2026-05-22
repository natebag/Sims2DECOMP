// 0x80337094 THPPlayerSetVolume(int, (300 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 28,0x10(1); stw 0,0x24(1); lis 9,-32691; mr 30,3; addi 29,9,14656; mr 31,4; lwz 0,0xa0(29); cmpwi 0,0; beq 8f; lbz 0,0xa7(29); cmpwi 0,0; beq 8f; bl _s80337094_0; li 28,48; cmpwi 3,0; bne 0f; li 28,32; 0:; cmpwi 30,127; ble 1f; li 30,127; 1:; cmpwi 30,0; bge 2f; li 30,0; 2:; li 0,0; ori 0,0,60000; cmpw 31,0; ble 3f; li 31,0; ori 31,31,60000; 3:; cmpwi 31,0; bge 4f; li 31,0; 4:; bl _s80337094_1; cmpwi 3,0; li 3,1; bne 5f; li 3,0; 5:; xoris 0,30,32768; stw 0,0xc(1); lis 10,17200; lis 11,-32702; cmpwi 31,0; stw 10,0x8(1); lfd f12,0x1aa0(11); lfd f0,0x8(1); fsub f0,f0,f12; frsp f0,f0; stfs f0,0xe0(29); beq 6f; mullw 11,28,31; lfs f13,0xdc(29); fsubs f13,f0,f13; xoris 0,11,32768; stw 11,0xe8(29); stw 0,0xc(1); stw 10,0x8(1); lfd f0,0x8(1); fsub f0,f0,f12; frsp f0,f0; fdivs f13,f13,f0; stfs f13,0xe4(29); b 7f; 6:; stfs f0,0xdc(29); stw 31,0xe8(29); 7:; bl _s80337094_2; li 3,1; b 9f; 8:; li 3,0; 9:; lwz 0,0x24(1); mtspr 8,0; lmw 28,0x10(1); addi 1,1,32"
extern "C" void _s80337094_0();
extern "C" void _s80337094_1();
extern "C" void _s80337094_2();
extern "C" void f_80337094() {}
