// 0x800B7A60 cSoundPlayer::PlayBySource(char (108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; mr 30,5; lwz 0,0x0(31); mr 3,4; cmpwi 0,0; beq 0f; lwz 0,0x8(31); cmpwi 0,0; beq 0f; cmpwi 3,0; beq 0f; cmpwi 30,-2; beq 0f; bl _s800B7A60_0; mr 4,3; mr 5,30; mr 3,31; bl _s800B7A60_1; 0:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s800B7A60_0();
extern "C" void _s800B7A60_1();
extern "C" void f_800B7A60() {}
