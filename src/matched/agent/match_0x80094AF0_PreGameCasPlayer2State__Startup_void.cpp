// 0x80094AF0 PreGameCasPlayer2State::Startup(void) (100 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); lis 9,-32697; li 4,1; addi 31,9,24012; lwz 3,0xb4(31); bl _s80094AF0_0; cmpwi 3,0; bne 0f; lwz 9,0xb4(31); li 0,1; b 1f; 0:; lwz 9,0xb4(31); li 0,-1; 1:; stw 0,0x3ac(9); lis 9,-32697; li 0,1; stw 0,-6504(9); lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s80094AF0_0();
extern "C" void f_80094AF0() {}
