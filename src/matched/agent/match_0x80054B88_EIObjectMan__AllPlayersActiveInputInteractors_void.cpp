// 0x80054B88 EIObjectMan::AllPlayersActiveInputInteractors(void) (196 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); bl _s80054B88_0; li 31,1; li 4,0; li 5,0; bl _s80054B88_1; cmpwi 3,0; bne 0f; bl _s80054B88_2; li 4,0; li 5,1; bl _s80054B88_3; cmpwi 3,0; bne 2f; bl _s80054B88_4; li 4,0; b 1f; 0:; lis 9,-32697; lwz 0,0x5c70(9); cmpwi 0,0; beq 2f; bl _s80054B88_5; li 4,1; li 5,0; bl _s80054B88_6; cmpwi 3,0; bne 2f; bl _s80054B88_7; li 4,1; li 5,1; bl _s80054B88_8; cmpwi 3,0; bne 2f; bl _s80054B88_9; li 4,1; 1:; li 5,7; bl _s80054B88_10; cmpwi 3,0; bne 2f; li 31,0; 2:; mr 3,31; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s80054B88_0();
extern "C" void _s80054B88_1();
extern "C" void _s80054B88_2();
extern "C" void _s80054B88_3();
extern "C" void _s80054B88_4();
extern "C" void _s80054B88_5();
extern "C" void _s80054B88_6();
extern "C" void _s80054B88_7();
extern "C" void _s80054B88_8();
extern "C" void _s80054B88_9();
extern "C" void _s80054B88_10();
extern "C" void f_80054B88() {}
