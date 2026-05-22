// 0x8001EB50 CameraManager::~CameraManager(void) (40 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); andi. 0,4,1; beq 0f; bl _s8001EB50_0; 0:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s8001EB50_0();
extern "C" void f_8001EB50() {}
