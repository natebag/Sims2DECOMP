// 0x8012D038 PlayerFamilyImpl::ClearFamily(void) (112 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; bl _s8012D038_0; addi 3,30,3292; bl _s8012D038_1; lwz 9,0x0(30); lwz 0,0x144(9); lha 3,0x140(9); mtspr 8,0; add 3,30,3; blrl; bl _s8012D038_2; addi 3,30,200; bl _s8012D038_3; addi 3,30,3240; li 4,0; li 5,50; bl _s8012D038_4; li 0,0; stw 0,0xd60(30); lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8012D038_0();
extern "C" void _s8012D038_1();
extern "C" void _s8012D038_2();
extern "C" void _s8012D038_3();
extern "C" void _s8012D038_4();
extern "C" void f_8012D038() {}
