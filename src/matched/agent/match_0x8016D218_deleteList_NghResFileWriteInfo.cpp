// 0x8016D218 deleteList(NghResFileWriteInfo (124 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 11,0x4(30); mulli 0,29,24; lwz 9,0x38(11); b 0f; lwz 11,0x4(30); rlwinm 0,29,5,0,26; lwz 9,0x3c(11); add 9,9,0; lfs f0,0x14(9); b 1f; lwz 11,0x4(30); rlwinm 0,29,5,0,26; lwz 9,0x28(11); add 9,9,0; lfs f0,0x1c(9); b 1f; lwz 11,0x4(30); mulli 0,29,24; lwz 9,0x2c(11); 0:; add 9,9,0; lfs f0,0xc(9); 1:; fctiwz f13,f0; stfd f13,0x10(1); lwz 3,0x14(1); b 2f; li 3,1; 2:; lwz 0,0x2c(1); mtspr 8,0; lmw 29,0x1c(1); addi 1,1,40"
extern "C" void f_8016D218() {}
