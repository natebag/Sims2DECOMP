// 0x80248A8C __srefill (372 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lwz 0,0x5c(31); cmpwi 0,0; bne 0f; lwz 0,-27948(13); stw 0,0x5c(31); 0:; lwz 3,0x5c(31); lwz 0,0x38(3); cmpwi 0,0; bne 1f; crxor 6,6,6; bl _s80248A8C_0; 1:; li 0,0; lhz 9,0xc(31); stw 0,0x4(31); andi. 0,9,32; bne 8f; andi. 0,9,4; bne 3f; andi. 0,9,16; beq 8f; andi. 0,9,8; beq 2f; mr 3,31; bl _s80248A8C_1; mr. 3,3; bne 8f; lhz 0,0xc(31); stw 3,0x18(31); rlwinm 0,0,0,29,27; stw 3,0x8(31); sth 0,0xc(31); 2:; lhz 0,0xc(31); ori 0,0,4; sth 0,0xc(31); b 4f; 3:; lwz 0,0x30(31); cmpwi 0,0; beq 4f; lwz 0,0x3c(31); cmpwi 0,0; stw 0,0x4(31); beq 4f; lwz 0,0x38(31); li 3,0; stw 0,0x0(31); b 10f; 4:; lwz 0,0x10(31); cmpwi 0,0; bne 5f; mr 3,31; bl _s80248A8C_2; 5:; lhz 0,0xc(31); andi. 9,0,3; beq 6f; lis 4,-32731; lwz 3,0x5c(31); addi 4,4,-30100; bl _s80248A8C_3; 6:; lwz 0,0x10(31); lwz 11,0x20(31); mr 4,0; lwz 3,0x1c(31); lwz 5,0x14(31); mtspr 8,11; stw 0,0x0(31); blrl; lhz 0,0xc(31); cmpwi 3,0; stw 3,0x4(31); rlwinm 0,0,0,19,17; sth 0,0xc(31); bgt 9f; bne 7f; ori 0,0,32; sth 0,0xc(31); b 8f; 7:; ori 0,0,64; li 9,0; sth 0,0xc(31); stw 9,0x4(31); 8:; li 3,-1; b 10f; 9:; li 3,0; 10:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s80248A8C_0();
extern "C" void _s80248A8C_1();
extern "C" void _s80248A8C_2();
extern "C" void _s80248A8C_3();
extern "C" void f_80248A8C() {}
