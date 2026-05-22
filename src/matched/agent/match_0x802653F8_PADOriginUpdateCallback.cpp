// 0x802653F8 PADOriginUpdateCallback (204 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); lis 0,-32768; stwu 1,-40(1); stw 31,0x24(1); addi 31,4,0; stw 30,0x20(1); stw 29,0x1c(1); mr 29,3; srw 30,0,29; lwz 3,-23180(13); and. 0,3,30; beq 1f; rlwinm. 0,31,0,28,31; bne 0f; mr 3,29; bl _s802653F8_0; 0:; rlwinm. 0,31,0,28,28; beq 1f; bl _s802653F8_1; addi 31,3,0; addi 3,30,0; bl _s802653F8_2; lwz 0,-23180(13); not 9,30; lwz 6,-23168(13); mr 3,29; lwz 5,-23164(13); lwz 4,-23160(13); and 8,0,9; lwz 0,-23156(13); and 7,6,9; and 6,5,9; and 5,4,9; stw 8,-23180(13); and 0,0,9; stw 7,-23168(13); li 4,0; stw 6,-23164(13); stw 5,-23160(13); stw 0,-23156(13); bl _s802653F8_3; mr 3,31; bl _s802653F8_4; 1:; lwz 0,0x2c(1); lwz 31,0x24(1); lwz 30,0x20(1); lwz 29,0x1c(1); addi 1,1,40; mtspr 8,0"
extern "C" void _s802653F8_0();
extern "C" void _s802653F8_1();
extern "C" void _s802653F8_2();
extern "C" void _s802653F8_3();
extern "C" void _s802653F8_4();
extern "C" void f_802653F8() {}
