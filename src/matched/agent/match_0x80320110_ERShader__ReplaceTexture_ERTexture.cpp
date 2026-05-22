// 0x80320110 ERShader::ReplaceTexture(ERTexture (272 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 26,0x8(1); stw 0,0x24(1); mr 29,3; mr 27,4; lwz 0,0x58(29); mr 26,5; andi. 9,0,2; beq 0f; lwz 3,0x18(29); bl _s80320110_0; b 8f; 0:; andi. 9,0,2; beq 1f; li 28,0; b 4f; 1:; lwz 0,0x14(29); cmpwi 0,0; beq 2f; mr 9,0; b 3f; 2:; lwz 11,0x18(29); li 9,0; cmpwi 11,0; beq 3f; lwz 9,0x14(11); 3:; lwz 0,0x4(9); rlwinm 28,0,6,31,31; 4:; cmpwi 28,0; bne 8f; rlwinm 30,26,2,0,29; addi 31,29,32; lwzx 3,31,30; cmpwi 3,0; beq 5f; bl _s80320110_1; stwx 28,31,30; 5:; stwx 27,31,30; mr 3,27; bl _s80320110_2; lwzx 9,31,30; addi 11,29,40; lwz 0,0x8(9); stwx 0,11,30; lwz 3,0x14(29); cmpwi 3,0; beq 6f; mr 10,3; b 7f; 6:; lwz 3,0x18(29); li 10,0; cmpwi 3,0; beq 7f; lwz 10,0x14(3); 7:; lwz 9,0xf0(10); mr 5,26; lwz 4,0x14(27); lha 3,0x38(9); lwz 0,0x3c(9); add 3,10,3; mtspr 8,0; blrl; 8:; lwz 0,0x24(1); mtspr 8,0; lmw 26,0x8(1); addi 1,1,32"
extern "C" void _s80320110_0();
extern "C" void _s80320110_1();
extern "C" void _s80320110_2();
extern "C" void f_80320110() {}
