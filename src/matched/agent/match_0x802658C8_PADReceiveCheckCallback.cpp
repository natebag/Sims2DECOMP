// 0x802658C8 PADReceiveCheckCallback (320 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-32(1); stw 31,0x1c(1); mr 31,3; lis 3,-32768; stw 30,0x18(1); stw 29,0x14(1); srw 29,3,31; lwz 0,-23180(13); and. 0,0,29; beq 1f; lwz 5,-23168(13); not 6,29; lwz 3,-23164(13); rlwinm. 0,4,0,28,31; and 5,5,6; and 3,3,6; stw 5,-23168(13); stw 3,-23164(13); rlwinm 3,4,0,0,23; bne 0f; rlwinm. 0,3,0,0,0; beq 0f; rlwinm. 0,3,0,11,11; beq 0f; rlwinm. 0,3,0,1,1; beq 0f; rlwinm. 0,3,0,5,5; bne 0f; rlwinm. 0,3,0,12,12; bne 0f; rlwinm. 0,3,0,13,13; bne 0f; mulli 4,31,12; lis 3,-32694; addi 0,3,-16400; lis 3,-32730; add 6,0,4; addi 8,3,21496; addi 3,31,0; addi 4,13,-27632; li 5,1; li 7,10; li 10,0; li 9,0; bl _s802658C8_0; b 1f; 0:; bl _s802658C8_1; addi 30,3,0; addi 3,29,0; bl _s802658C8_2; lwz 0,-23180(13); not 9,29; lwz 6,-23168(13); mr 3,31; lwz 5,-23164(13); lwz 4,-23160(13); and 8,0,9; lwz 0,-23156(13); and 7,6,9; and 6,5,9; and 5,4,9; stw 8,-23180(13); and 0,0,9; stw 7,-23168(13); li 4,0; stw 6,-23164(13); stw 5,-23160(13); stw 0,-23156(13); bl _s802658C8_3; mr 3,30; bl _s802658C8_4; 1:; lwz 0,0x24(1); lwz 31,0x1c(1); lwz 30,0x18(1); lwz 29,0x14(1); addi 1,1,32; mtspr 8,0"
extern "C" void _s802658C8_0();
extern "C" void _s802658C8_1();
extern "C" void _s802658C8_2();
extern "C" void _s802658C8_3();
extern "C" void _s802658C8_4();
extern "C" void f_802658C8() {}
