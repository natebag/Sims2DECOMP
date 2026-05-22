// 0x80352718 Effects::EffectsManager::DeleteEffect(Effects::Effect (128 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 28,0x10(1); stw 0,0x24(1); mr 31,3; lwz 0,0x0(31); cmpwi 0,0; bne 0f; li 3,0; b 2f; 0:; addi 28,1,8; addi 29,31,4; mr 3,31; mr 5,29; mr 6,28; bl _s80352718_0; mr. 30,3; beq 1f; mr 4,30; mr 5,29; mr 6,28; mr 3,31; bl _s80352718_1; mr 3,31; mr 4,30; bl _s80352718_2; 1:; li 3,1; 2:; lwz 0,0x24(1); mtspr 8,0; lmw 28,0x10(1); addi 1,1,32"
extern "C" void _s80352718_0();
extern "C" void _s80352718_1();
extern "C" void _s80352718_2();
extern "C" void f_80352718() {}
