// 0x8003FAAC EGlobal::TransformToWorld(EVec2 (80 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; mr 30,4; mr 29,5; bl _s8003FAAC_0; cmpwi 3,0; beq 0f; mr 3,31; bl _s8003FAAC_1; mr 4,30; mr 5,29; bl _s8003FAAC_2; 0:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8003FAAC_0();
extern "C" void _s8003FAAC_1();
extern "C" void _s8003FAAC_2();
extern "C" void f_8003FAAC() {}
