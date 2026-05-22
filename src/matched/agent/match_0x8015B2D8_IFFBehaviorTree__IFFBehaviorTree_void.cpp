// 0x8015B2D8 IFFBehaviorTree::IFFBehaviorTree(void) (68 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; bl _s8015B2D8_0; lis 9,-32698; li 0,0; addi 9,9,22480; stw 0,0x60(30); stw 9,0x0(30); mr 3,30; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8015B2D8_0();
extern "C" void f_8015B2D8() {}
