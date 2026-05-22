// 0x803523D0 Effects::EffectsManager::Update(float) (356 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stfd f31,0x20(1); stmw 29,0x14(1); stw 0,0x2c(1); mr 29,3; fmr f31,f1; lwz 0,0x0(29); cmpwi 0,0; beq 10f; bl _s803523D0_0; lwz 0,0x4(29); stw 0,0x8(1); b 5f; 0:; lwz 31,0x0(9); li 10,1; lwz 30,0x8(9); lwz 11,0x8(31); lwz 0,0x140(11); andi. 9,0,1024; bne 1f; li 10,0; 1:; cmpwi 10,0; beq 4f; li 9,1; andi. 10,0,8192; bne 2f; li 9,0; 2:; cmpwi 9,0; beq 3f; mr 4,31; addi 5,29,4; addi 6,1,8; mr 3,29; bl _s803523D0_1; mr 4,31; mr 3,29; bl _s803523D0_2; b 4f; 3:; lwz 9,0x144(11); fmr f1,f31; lha 3,0x10(9); lwz 0,0x14(9); add 3,11,3; mtspr 8,0; blrl; 4:; stw 30,0x8(1); 5:; lwz 9,0x8(1); li 0,1; cmpwi 9,0; bne 6f; li 0,0; 6:; cmpwi 0,0; bne 0b; lwz 31,0x10(29); 7:; cmpwi 31,0; beq 10f; lwz 30,0x0(31); lwz 9,0x0(30); addi 9,9,1; cmpwi 9,3; stw 9,0x0(30); bne 9f; lwz 11,0x8(30); cmpwi 11,0; beq 8f; lwz 9,0x144(11); li 4,3; lha 3,0x8(9); lwz 0,0xc(9); add 3,11,3; mtspr 8,0; blrl; 8:; mr 3,30; bl _s803523D0_3; lwz 30,0x8(31); mr 4,31; addi 3,29,16; bl _s803523D0_4; mr 31,30; b 7b; 9:; lwz 31,0x8(31); b 7b; 10:; lwz 0,0x2c(1); mtspr 8,0; lmw 29,0x14(1); lfd f31,0x20(1); addi 1,1,40"
extern "C" void _s803523D0_0();
extern "C" void _s803523D0_1();
extern "C" void _s803523D0_2();
extern "C" void _s803523D0_3();
extern "C" void _s803523D0_4();
extern "C" void f_803523D0() {}
