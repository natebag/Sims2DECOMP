// 0x80247BC0 __swsetup (232 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lwz 0,0x5c(31); cmpwi 0,0; bne 0f; lwz 0,-27948(13); stw 0,0x5c(31); 0:; lwz 3,0x5c(31); lwz 0,0x38(3); cmpwi 0,0; bne 1f; crxor 6,6,6; bl _s80247BC0_0; 1:; lhz 0,0xc(31); andi. 11,0,8; bne 4f; andi. 9,0,16; bne 2f; li 3,-1; b 9f; 2:; andi. 9,0,4; beq 3f; lwz 9,0x10(31); andi. 0,0,65499; sth 0,0xc(31); stw 11,0x4(31); stw 9,0x0(31); 3:; lhz 0,0xc(31); ori 0,0,8; sth 0,0xc(31); 4:; lwz 0,0x10(31); cmpwi 0,0; bne 5f; mr 3,31; bl _s80247BC0_1; 5:; lhz 0,0xc(31); andi. 9,0,1; beq 6f; lwz 0,0x14(31); li 9,0; stw 9,0x8(31); neg 0,0; stw 0,0x18(31); b 8f; 6:; andi. 9,0,2; li 0,0; bne 7f; lwz 0,0x14(31); 7:; stw 0,0x8(31); 8:; li 3,0; 9:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s80247BC0_0();
extern "C" void _s80247BC0_1();
extern "C" void f_80247BC0() {}
