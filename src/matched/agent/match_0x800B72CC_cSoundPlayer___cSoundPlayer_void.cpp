// 0x800B72CC cSoundPlayer::~cSoundPlayer(void) (156 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; mr 29,4; lwz 0,0x8(31); cmpwi 0,0; beq 1f; lwz 11,0x4(31); cmpwi 11,0; beq 0f; lwz 9,0x0(11); li 4,3; lha 3,0x8(9); lwz 0,0xc(9); add 3,11,3; mtspr 8,0; blrl; 0:; li 0,0; stw 0,-24464(13); stw 0,0x4(31); 1:; addi 30,31,24; mr 3,30; bl _s800B72CC_0; lwz 3,0x4(30); cmpwi 3,0; beq 2f; li 4,20; bl _s800B72CC_1; 2:; andi. 0,29,1; beq 3f; mr 3,31; bl _s800B72CC_2; 3:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s800B72CC_0();
extern "C" void _s800B72CC_1();
extern "C" void _s800B72CC_2();
extern "C" void f_800B72CC() {}
