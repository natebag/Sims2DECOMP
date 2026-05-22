// 0x8035A424 EConfig::Close(bool, (240 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 26,0x8(1); stw 0,0x24(1); mr 29,3; mr 11,4; lwz 9,0x4(29); mr 4,6; li 26,0; lbz 0,0x0(9); cmpwi 0,0; beq 2f; lwz 0,0x0(29); cmpwi 0,0; bne 0f; cmpwi 5,0; beq 1f; 0:; cmpwi 11,0; beq 1f; mr 3,29; bl _s8035A424_0; mr 26,3; b 2f; 1:; li 26,1; 2:; addi 3,29,4; addi 28,29,8; bl _s8035A424_1; lwz 9,0x4(28); addi 27,29,20; b 5f; 3:; lwz 0,0x8(28); lwz 31,0x0(9); cmpwi 0,0; lwz 30,0x4(9); beq 4f; cmpwi 31,0; beq 4f; lwz 4,0x0(31); mr 3,31; bl _s8035A424_2; mr 3,31; bl _s8035A424_3; 4:; mr 9,30; 5:; li 31,1; cmpwi 9,0; bne 6f; li 31,0; 6:; cmpwi 31,0; bne 3b; mr 3,28; bl _s8035A424_4; mr 3,27; bl _s8035A424_5; stw 31,0x0(29); mr 3,26; lwz 0,0x24(1); mtspr 8,0; lmw 26,0x8(1); addi 1,1,32"
extern "C" void _s8035A424_0();
extern "C" void _s8035A424_1();
extern "C" void _s8035A424_2();
extern "C" void _s8035A424_3();
extern "C" void _s8035A424_4();
extern "C" void _s8035A424_5();
extern "C" void f_8035A424() {}
