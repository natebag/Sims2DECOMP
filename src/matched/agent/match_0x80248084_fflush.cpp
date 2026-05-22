// 0x80248084 fflush (244 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr. 31,3; bne 0f; lis 4,-32731; lwz 3,-27948(13); addi 4,4,-32636; bl _s80248084_0; b 8f; 0:; lwz 0,0x5c(31); cmpwi 0,0; bne 1f; lwz 0,-27948(13); stw 0,0x5c(31); 1:; lwz 3,0x5c(31); lwz 0,0x38(3); cmpwi 0,0; bne 2f; crxor 6,6,6; bl _s80248084_1; 2:; lha 3,0xc(31); andi. 0,3,8; beq 7f; lwz 29,0x10(31); cmpwi 29,0; beq 7f; lwz 0,0x0(31); andi. 9,3,3; stw 29,0x0(31); subf 30,29,0; bne 4f; lwz 0,0x14(31); b 5f; 3:; lhz 0,0xc(31); li 3,-1; ori 0,0,64; sth 0,0xc(31); b 8f; 4:; li 0,0; 5:; stw 0,0x8(31); cmpwi 30,0; ble 7f; 6:; lwz 9,0x24(31); mr 4,29; lwz 3,0x1c(31); mr 5,30; mtspr 8,9; blrl; mr. 3,3; ble 3b; add 29,29,3; subf. 30,3,30; bgt 6b; 7:; li 3,0; 8:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s80248084_0();
extern "C" void _s80248084_1();
extern "C" void f_80248084() {}
