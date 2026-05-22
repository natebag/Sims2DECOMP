// 0x8028FEC8 AptCIH::Remove(void) (292 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lwz 3,-22996(13); mr 4,31; bl _s8028FEC8_0; lwz 9,-23008(13); lwz 0,0x64(9); cmpw 0,31; bne 0f; lwz 9,0x8(31); lis 4,-32704; lis 5,-32704; addi 4,4,22776; lwz 0,0x14(9); addi 5,5,22800; lha 3,0x10(9); li 6,122; mtspr 8,0; add 3,31,3; blrl; lwz 9,-23008(13); li 0,0; stw 0,0x64(9); 0:; lis 9,-32694; lwz 0,-15940(9); cmpwi 0,0; beq 1f; mr 3,31; li 4,0; bl _s8028FEC8_1; b 2f; 1:; mr 3,31; li 4,1; bl _s8028FEC8_2; 2:; lwz 9,-23008(13); mr 4,31; lwz 3,0x98(9); bl _s8028FEC8_3; lwz 3,-23008(13); mr 4,31; bl _s8028FEC8_4; lwz 0,0x0(31); rlwinm 0,0,18,20,31; cmplwi 0,1; ble 3f; mr 3,31; bl _s8028FEC8_5; lwz 0,0x5c(31); rlwinm 9,0,20,30,31; cmpwi 9,0; bne 3f; lwz 0,0x0(31); rlwimi 0,9,27,4,4; stw 0,0x0(31); 3:; lwz 9,0x8(31); lis 4,-32704; lis 5,-32704; addi 4,4,22776; lha 3,0x10(9); addi 5,5,22800; lwz 0,0x14(9); li 6,151; add 3,31,3; mtspr 8,0; blrl; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s8028FEC8_0();
extern "C" void _s8028FEC8_1();
extern "C" void _s8028FEC8_2();
extern "C" void _s8028FEC8_3();
extern "C" void _s8028FEC8_4();
extern "C" void _s8028FEC8_5();
extern "C" void f_8028FEC8() {}
