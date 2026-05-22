// 0x80144D24 IFFSlotDescList::LoadFromDataID(ObjectDataID (212 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,4; mr 29,3; addi 3,29,76; bl _s80144D24_0; lwz 11,-21508(13); lwz 4,0x0(30); lwz 9,0x0(11); lwz 0,0x3c(9); lha 3,0x38(9); mtspr 8,0; add 3,11,3; blrl; mr 31,3; lis 4,21324; lwz 9,0xc(31); ori 4,4,20308; lha 5,0x4(30); li 6,0; lha 3,0x80(9); lwz 0,0x84(9); add 3,31,3; mtspr 8,0; blrl; mr. 3,3; beq 0f; lwz 9,0xc(31); mr 4,3; addi 5,29,4; lwz 0,0xa4(9); lha 3,0xa0(9); mtspr 8,0; add 3,31,3; blrl; lha 6,0x4(30); lis 5,21324; addi 3,29,84; mr 4,31; ori 5,5,20308; li 7,0; bl _s80144D24_1; subfic 0,3,0; adde 3,0,3; b 1f; 0:; li 3,0; 1:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s80144D24_0();
extern "C" void _s80144D24_1();
extern "C" void f_80144D24() {}
