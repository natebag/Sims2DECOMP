// 0x8015B31C IFFBehaviorTree::IFFBehaviorTree(int) (96 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 29,3; mr 30,4; bl _s8015B31C_0; mulli 30,30,12; lis 9,-32698; addi 9,9,22480; stw 9,0x0(29); addi 3,30,24; bl _s8015B31C_1; stw 3,0x54(29); li 0,1; li 9,0; stw 0,0x8(29); stw 9,0x60(29); mr 3,29; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8015B31C_0();
extern "C" void _s8015B31C_1();
extern "C" void f_8015B31C() {}
