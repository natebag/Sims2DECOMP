// 0x8032695C EResourceManager::addRef(unsigned (260 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 27,0x14(1); stw 0,0x2c(1); lwz 11,-22652(13); mr 28,3; mr 31,4; mr 30,5; lwz 9,0x0(11); mr 29,6; mr 27,7; lha 3,0x118(9); lwz 0,0x11c(9); add 3,11,3; mtspr 8,0; blrl; cmpwi 3,0; beq 0f; lwz 3,-26824(13); bl _s8032695C_0; 0:; cmpwi 31,0; bne 1f; li 3,0; b 4f; 1:; li 0,0; mr 3,28; stw 0,0x8(1); mr 4,31; addi 5,1,8; bl _s8032695C_1; cmpwi 3,0; beq 2f; cmpwi 29,0; beq 3f; cmpwi 30,0; beq 3f; lwz 9,0x28(30); mr 4,29; li 5,1; lha 3,0x28(9); lwz 0,0x2c(9); add 3,30,3; mtspr 8,0; blrl; b 3f; 2:; lwz 3,-22652(13); mr 4,28; mr 5,31; mr 6,30; lwz 11,0x0(3); mr 8,29; mr 9,27; li 7,0; lha 0,0x50(11); lwz 11,0x54(11); add 3,3,0; mtspr 8,11; blrl; stw 3,0x8(1); 3:; lwz 3,0x8(1); 4:; lwz 0,0x2c(1); mtspr 8,0; lmw 27,0x14(1); addi 1,1,40"
extern "C" void _s8032695C_0();
extern "C" void _s8032695C_1();
extern "C" void f_8032695C() {}
