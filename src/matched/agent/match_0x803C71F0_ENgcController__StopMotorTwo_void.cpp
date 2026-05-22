// 0x803C71F0 ENgcController::StopMotorTwo(void) (68 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; bl _s803C71F0_0; cmpwi 3,0; li 3,0; beq 0f; mr 3,31; bl _s803C71F0_1; li 3,1; 0:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s803C71F0_0();
extern "C" void _s803C71F0_1();
extern "C" void f_803C71F0() {}
