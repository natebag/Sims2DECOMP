// 0x803A57AC void (168 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 26,0x10(1); stw 0,0x2c(1); mr 28,3; mr 26,4; mr 27,5; cmpw 28,26; beq 4f; addi 31,28,4; cmpw 31,26; beq 4f; 0:; addi 3,1,8; mr 4,28; mtspr 8,27; lwz 29,0x0(31); stw 29,0x8(1); blrl; cmpwi 3,0; beq 2f; addi 30,31,4; subf. 0,28,31; ble 1f; mr 5,0; subf 3,0,30; mr 4,28; bl _s803A57AC_0; 1:; stw 29,0x0(28); b 3f; 2:; mr 4,29; mr 3,31; mr 5,27; bl _s803A57AC_1; addi 30,31,4; 3:; mr 31,30; cmpw 31,26; bne 0b; 4:; lwz 0,0x2c(1); mtspr 8,0; lmw 26,0x10(1); addi 1,1,40"
extern "C" void _s803A57AC_0();
extern "C" void _s803A57AC_1();
extern "C" void f_803A57AC() {}
