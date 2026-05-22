// 0x803527D0 Effects::EffectsManager::AddEffect(Effects::Effect (144 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; mr 29,4; li 3,12; bl _s803527D0_0; mr 31,3; li 0,0; mr 3,30; stw 0,0x4(31); stw 0,0x0(31); mr 4,31; stw 29,0x8(31); addi 5,3,4; bl _s803527D0_1; mr. 30,3; bne 1f; cmpwi 29,0; beq 0f; lwz 9,0x144(29); li 4,3; lha 3,0x8(9); lwz 0,0xc(9); add 3,29,3; mtspr 8,0; blrl; 0:; mr 3,31; bl _s803527D0_2; 1:; mr 3,30; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s803527D0_0();
extern "C" void _s803527D0_1();
extern "C" void _s803527D0_2();
extern "C" void f_803527D0() {}
