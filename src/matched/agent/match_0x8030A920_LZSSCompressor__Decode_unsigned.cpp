// 0x8030A920 LZSSCompressor::Decode(unsigned (380 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 25,0xc(1); stw 0,0x2c(1); mr 25,5; li 0,0; add 4,3,4; add 6,25,6; stw 0,-26692(13); li 27,0; stw 0,-26672(13); stw 0,-26696(13); stw 4,-26684(13); stw 6,-26676(13); stw 3,-26688(13); stw 25,-26680(13); bl _s8030A920_0; li 4,4113; li 5,0; bl _s8030A920_1; li 9,4078; stw 3,-22680(13); mtspr 9,9; li 0,0; 0:; lwz 9,-22680(13); stbx 0,9,27; addi 27,27,1; bdnz 0b; li 28,4078; li 26,0; b 4f; 1:; mr 3,31; bl _s8030A920_2; lwz 9,-22680(13); stbx 31,9,28; addi 28,28,1; rlwinm 28,28,0,20,31; b 4f; 2:; bl _s8030A920_3; mr 27,3; cmpwi 27,-1; beq 6f; bl _s8030A920_4; mr 30,3; cmpwi 30,-1; beq 6f; rlwinm 0,30,4,20,23; rlwinm 9,30,0,28,31; addi 30,9,2; or 27,27,0; cmpw 31,30; li 29,0; bgt 4f; 3:; add 9,27,29; lwz 11,-22680(13); rlwinm 9,9,0,20,31; addi 29,29,1; lbzx 31,11,9; mr 3,31; bl _s8030A920_5; lwz 9,-22680(13); cmpw 29,30; stbx 31,9,28; addi 28,28,1; rlwinm 28,28,0,20,31; ble 3b; 4:; rlwinm 26,26,31,1,31; andi. 0,26,256; bne 5f; bl _s8030A920_6; mr 31,3; cmpwi 31,-1; beq 6f; ori 26,31,65280; 5:; andi. 31,26,1; beq 2b; bl _s8030A920_7; mr 31,3; cmpwi 31,-1; bne 1b; 6:; bl _s8030A920_8; lwz 4,-22680(13); bl _s8030A920_9; lwz 0,-26672(13); cmpwi 0,0; bne 7f; lwz 3,-26680(13); subf 3,25,3; b 8f; 7:; li 3,-1; 8:; lwz 0,0x2c(1); mtspr 8,0; lmw 25,0xc(1); addi 1,1,40"
extern "C" void _s8030A920_0();
extern "C" void _s8030A920_1();
extern "C" void _s8030A920_2();
extern "C" void _s8030A920_3();
extern "C" void _s8030A920_4();
extern "C" void _s8030A920_5();
extern "C" void _s8030A920_6();
extern "C" void _s8030A920_7();
extern "C" void _s8030A920_8();
extern "C" void _s8030A920_9();
extern "C" void f_8030A920() {}
