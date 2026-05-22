// 0x8020B450 InteractorModule::InteractorManager::Shutdown(void) (120 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; lwz 0,0x0(30); cmpwi 0,0; beq 2f; bl _s8020B450_0; lwz 3,-28508(13); bl _s8020B450_1; lwz 3,-28508(13); cmpwi 3,0; beq 0f; li 4,3; bl _s8020B450_2; 0:; lwz 3,-28512(13); li 31,0; stw 31,-28508(13); cmpwi 3,0; beq 1f; li 4,3; bl _s8020B450_3; 1:; stw 31,-28512(13); stw 31,0x0(30); 2:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8020B450_0();
extern "C" void _s8020B450_1();
extern "C" void _s8020B450_2();
extern "C" void _s8020B450_3();
extern "C" void f_8020B450() {}
