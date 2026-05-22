// 0x803A5F34 void (172 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 27,0x14(1); stw 0,0x2c(1); mr 29,3; mr 27,4; mr 28,5; cmpw 29,27; beq 4f; addi 31,29,4; cmpw 31,27; beq 4f; 0:; addi 3,1,8; mr 4,29; mtspr 8,28; lwz 0,0x0(31); stw 0,0x8(1); blrl; cmpwi 3,0; beq 2f; addi 30,31,4; subf. 0,29,31; ble 1f; mr 5,0; subf 3,0,30; mr 4,29; bl _s803A5F34_0; 1:; lwz 0,0x8(1); stw 0,0x0(29); b 3f; 2:; lwz 4,0x8(1); mr 3,31; mr 5,28; bl _s803A5F34_1; addi 30,31,4; 3:; mr 31,30; cmpw 31,27; bne 0b; 4:; lwz 0,0x2c(1); mtspr 8,0; lmw 27,0x14(1); addi 1,1,40"
extern "C" void _s803A5F34_0();
extern "C" void _s803A5F34_1();
extern "C" void f_803A5F34() {}
