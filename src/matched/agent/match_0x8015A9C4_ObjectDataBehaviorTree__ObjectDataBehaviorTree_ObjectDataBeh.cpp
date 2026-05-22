// 0x8015A9C4 ObjectDataBehaviorTree::ObjectDataBehaviorTree(ObjectDataBehaviorTree (188 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-96(1); mfspr 0,8; stmw 28,0x50(1); stw 0,0x64(1); lis 9,-32698; mr 30,3; mr 28,4; addi 9,9,22720; stw 9,0x0(30); addi 4,30,20; li 5,64; addi 3,30,12; bl _s8015A9C4_0; addi 29,1,8; li 4,0; li 5,0; addi 3,30,88; bl _s8015A9C4_1; lwz 9,0x54(28); li 0,0; li 5,64; stw 0,0x8(30); stw 9,0x54(30); addi 4,29,8; mr 3,29; bl _s8015A9C4_2; lwz 9,0x0(28); mr 4,29; lha 3,0x40(9); lwz 0,0x44(9); add 3,28,3; mtspr 8,0; blrl; mr 4,29; mr 3,30; bl _s8015A9C4_3; mr 3,28; bl _s8015A9C4_4; mr 4,3; mr 3,30; bl _s8015A9C4_5; mr 3,30; lwz 0,0x64(1); mtspr 8,0; lmw 28,0x50(1); addi 1,1,96"
extern "C" void _s8015A9C4_0();
extern "C" void _s8015A9C4_1();
extern "C" void _s8015A9C4_2();
extern "C" void _s8015A9C4_3();
extern "C" void _s8015A9C4_4();
extern "C" void _s8015A9C4_5();
extern "C" void f_8015A9C4() {}
