// 0x802C71CC EFileSystem::ParseMode(char (156 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,4; mr 29,5; mr 3,30; li 4,114; bl _s802C71CC_0; li 31,0; cmpwi 3,0; beq 0f; li 31,1; 0:; mr 3,30; li 4,119; bl _s802C71CC_1; cmpwi 3,0; beq 1f; oris 0,31,1; ori 31,0,2; 1:; mr 3,30; li 4,97; bl _s802C71CC_2; cmpwi 3,0; beq 2f; ori 31,31,6; 2:; mr 3,30; li 4,43; bl _s802C71CC_3; cmpwi 3,0; beq 3f; ori 31,31,3; 3:; stw 31,0x0(29); li 3,1; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s802C71CC_0();
extern "C" void _s802C71CC_1();
extern "C" void _s802C71CC_2();
extern "C" void _s802C71CC_3();
extern "C" void f_802C71CC() {}
