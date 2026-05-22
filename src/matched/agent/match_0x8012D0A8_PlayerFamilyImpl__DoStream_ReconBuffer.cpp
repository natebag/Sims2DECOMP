// 0x8012D0A8 PlayerFamilyImpl::DoStream(ReconBuffer (152 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; mr 29,4; mr 30,5; bl _s8012D0A8_0; mr 4,29; mr 5,30; addi 3,31,56; bl _s8012D0A8_1; addi 3,31,3292; mr 4,29; mr 5,30; bl _s8012D0A8_2; addi 3,31,200; mr 4,29; mr 5,30; bl _s8012D0A8_3; mr 3,29; addi 4,31,3240; li 5,25; bl _s8012D0A8_4; cmpwi 30,17; ble 0f; mr 3,29; addi 4,31,3424; li 5,1; bl _s8012D0A8_5; b 1f; 0:; li 0,0; stw 0,0xd60(31); 1:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8012D0A8_0();
extern "C" void _s8012D0A8_1();
extern "C" void _s8012D0A8_2();
extern "C" void _s8012D0A8_3();
extern "C" void _s8012D0A8_4();
extern "C" void _s8012D0A8_5();
extern "C" void f_8012D0A8() {}
