// 0x8003B1E4 GameData::GamePlayShutdown(void) (72 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lis 9,-32697; li 0,0; stw 0,0x5e94(9); lwz 11,-21476(13); lwz 9,0x0(11); lha 3,0x190(9); lwz 0,0x194(9); add 3,11,3; mtspr 8,0; blrl; bl _s8003B1E4_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s8003B1E4_0();
extern "C" void f_8003B1E4() {}
