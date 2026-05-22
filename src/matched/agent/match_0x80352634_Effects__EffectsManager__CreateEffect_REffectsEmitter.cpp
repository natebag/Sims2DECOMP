// 0x80352634 Effects::EffectsManager::CreateEffect(REffectsEmitter (220 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; mr 29,4; lwz 0,0x0(30); mr 31,5; cmpwi 0,0; bne 1f; 0:; li 3,0; b 5f; 1:; cmpwi 31,0; beq 2f; bl _s80352634_0; li 4,424; li 5,16; li 6,0; li 7,0; bl _s80352634_1; mr 4,31; bl _s80352634_2; b 3f; 2:; bl _s80352634_3; li 4,424; li 5,16; li 6,0; li 7,0; bl _s80352634_4; bl _s80352634_5; 3:; mr 31,3; mr 4,29; mr 3,31; bl _s80352634_6; cmpwi 3,0; bne 4f; cmpwi 31,0; beq 0b; lwz 9,0x144(31); li 4,3; lha 3,0x8(9); lwz 0,0xc(9); add 3,31,3; mtspr 8,0; blrl; b 0b; 4:; mr 3,30; mr 4,31; bl _s80352634_7; mr 3,31; 5:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s80352634_0();
extern "C" void _s80352634_1();
extern "C" void _s80352634_2();
extern "C" void _s80352634_3();
extern "C" void _s80352634_4();
extern "C" void _s80352634_5();
extern "C" void _s80352634_6();
extern "C" void _s80352634_7();
extern "C" void f_80352634() {}
