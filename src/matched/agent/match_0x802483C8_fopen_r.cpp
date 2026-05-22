// 0x802483C8 _fopen_r (236 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 29,0x14(1); stw 0,0x24(1); mr 30,4; mr 31,3; mr 4,5; addi 5,1,8; bl _s802483C8_0; mr. 29,3; li 3,0; beq 3f; mr 3,31; bl _s802483C8_1; mr. 31,3; bne 0f; li 3,0; b 3f; 0:; lhz 0,0xc(31); mr 4,30; lwz 3,0x5c(31); li 6,438; rlwinm 0,0,0,30,30; sth 0,0xc(31); lwz 5,0x8(1); bl _s802483C8_2; mr. 3,3; bge 1f; li 0,0; li 3,0; sth 0,0xc(31); b 3f; 1:; lis 9,-32731; lis 11,-32731; lis 10,-32731; lis 8,-32731; addi 9,9,-29696; addi 11,11,-29596; addi 10,10,-29484; addi 8,8,-29384; sth 3,0xe(31); andi. 0,29,256; stw 9,0x20(31); stw 11,0x24(31); stw 10,0x28(31); stw 8,0x2c(31); sth 29,0xc(31); stw 31,0x1c(31); beq 2f; mr 3,31; li 4,0; li 5,2; bl _s802483C8_3; 2:; mr 3,31; 3:; lwz 0,0x24(1); mtspr 8,0; lmw 29,0x14(1); addi 1,1,32"
extern "C" void _s802483C8_0();
extern "C" void _s802483C8_1();
extern "C" void _s802483C8_2();
extern "C" void _s802483C8_3();
extern "C" void f_802483C8() {}
