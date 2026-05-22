// 0x802119EC InteractorModule::AllPlayersActiveInputInteractors(int) (212 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); lis 9,-32697; li 31,1; lwz 0,0x5c70(9); cmpwi 0,0; beq 2f; cmpwi 3,1; bne 0f; bl _s802119EC_0; li 4,0; li 5,1; bl _s802119EC_1; cmpwi 3,0; bne 2f; bl _s802119EC_2; li 4,0; li 5,0; bl _s802119EC_3; cmpwi 3,0; bne 2f; bl _s802119EC_4; li 4,0; li 5,7; bl _s802119EC_5; b 1f; 0:; bl _s802119EC_6; li 4,1; li 5,1; bl _s802119EC_7; cmpwi 3,0; bne 2f; bl _s802119EC_8; li 4,1; li 5,0; bl _s802119EC_9; cmpwi 3,0; bne 2f; bl _s802119EC_10; li 4,1; li 5,7; bl _s802119EC_11; 1:; cmpwi 3,0; bne 2f; li 31,0; 2:; mr 3,31; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s802119EC_0();
extern "C" void _s802119EC_1();
extern "C" void _s802119EC_2();
extern "C" void _s802119EC_3();
extern "C" void _s802119EC_4();
extern "C" void _s802119EC_5();
extern "C" void _s802119EC_6();
extern "C" void _s802119EC_7();
extern "C" void _s802119EC_8();
extern "C" void _s802119EC_9();
extern "C" void _s802119EC_10();
extern "C" void _s802119EC_11();
extern "C" void f_802119EC() {}
