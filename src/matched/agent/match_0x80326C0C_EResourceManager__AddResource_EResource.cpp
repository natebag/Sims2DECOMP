// 0x80326C0C EResourceManager::AddResource(EResource (236 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 27,0x14(1); stw 0,0x2c(1); mr 31,3; mr 29,5; mr 27,6; mr. 30,4; beq 2f; stw 31,0x8(1); li 4,-1; addi 28,31,3336; lwz 9,0x0(31); lha 3,0x10(9); lwz 0,0x14(9); add 3,31,3; mtspr 8,0; blrl; lwz 7,0x40(31); mr 3,28; mr 4,31; mr 5,29; mr 6,30; bl _s80326C0C_0; cmpwi 3,0; bne 0f; mr 3,28; mr 4,29; addi 5,1,12; bl _s80326C0C_1; cmpwi 3,0; beq 1f; lhz 9,0xc(30); addi 9,9,1; sth 9,0xc(30); b 1f; 0:; lwz 0,0x10(30); stw 31,0x4(30); rlwimi 0,27,7,24,24; stw 29,0x8(30); stw 0,0x10(30); 1:; lwz 9,0x0(30); lwz 0,0x5c(9); lha 3,0x58(9); mtspr 8,0; add 3,30,3; blrl; lwz 11,0x8(1); lwz 9,0x0(11); lha 3,0x18(9); lwz 0,0x1c(9); add 3,11,3; mtspr 8,0; blrl; 2:; lwz 0,0x2c(1); mtspr 8,0; lmw 27,0x14(1); addi 1,1,40"
extern "C" void _s80326C0C_0();
extern "C" void _s80326C0C_1();
extern "C" void f_80326C0C() {}
