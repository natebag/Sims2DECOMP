// 0x80144F34 IFFSlotDescList::SaveDataByID(ObjectDataID (112 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); lwz 11,-21508(13); mr 29,3; mr 30,4; lwz 9,0x0(11); lwz 4,0x0(30); lwz 0,0x3c(9); lha 3,0x38(9); mtspr 8,0; add 3,11,3; blrl; mr 4,3; lha 6,0x4(30); lis 5,21324; addi 3,29,84; ori 5,5,20308; li 7,0; bl _s80144F34_0; subfic 0,3,0; adde 3,0,3; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s80144F34_0();
extern "C" void f_80144F34() {}
