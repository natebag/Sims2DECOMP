// 0x8015A908 ObjectDataBehaviorTree::ObjectDataBehaviorTree(void) (136 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 30,3; li 27,0; lis 9,-32698; li 0,0; addi 9,9,22720; addi 28,30,12; stw 27,0x8(30); lis 29,-32706; stw 9,0x0(30); addi 29,29,-8260; sth 0,0x4(30); addi 4,30,20; li 5,64; mr 3,28; bl _s8015A908_0; mr 3,28; mr 4,29; li 5,-1; bl _s8015A908_1; stw 27,0x54(30); addi 3,30,88; li 4,0; li 5,0; bl _s8015A908_2; mr 3,30; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s8015A908_0();
extern "C" void _s8015A908_1();
extern "C" void _s8015A908_2();
extern "C" void f_8015A908() {}
