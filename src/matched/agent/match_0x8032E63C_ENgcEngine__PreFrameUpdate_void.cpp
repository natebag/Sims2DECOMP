// 0x8032E63C ENgcEngine::PreFrameUpdate(void) (64 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; bl _s8032E63C_0; cmpwi 3,0; beq 0f; .long 0x00000002; 0:; mr 3,31; bl _s8032E63C_1; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s8032E63C_0();
extern "C" void _s8032E63C_1();
extern "C" void f_8032E63C() {}
