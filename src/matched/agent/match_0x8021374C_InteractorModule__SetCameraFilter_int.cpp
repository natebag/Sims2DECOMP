// 0x8021374C InteractorModule::SetCameraFilter(int) (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; bl _s8021374C_0; mr 4,31; bl _s8021374C_1; mr. 30,3; beq 0f; bl _s8021374C_2; mr 4,31; bl _s8021374C_3; mr. 31,3; li 3,0; beq 1f; mr 3,30; bl _s8021374C_4; mr 4,3; mr 3,31; bl _s8021374C_5; li 3,1; b 1f; 0:; li 3,0; 1:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8021374C_0();
extern "C" void _s8021374C_1();
extern "C" void _s8021374C_2();
extern "C" void _s8021374C_3();
extern "C" void _s8021374C_4();
extern "C" void _s8021374C_5();
extern "C" void f_8021374C() {}
