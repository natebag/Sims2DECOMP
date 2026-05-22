// 0x80206134 InteractorModule::DirectInteractor::CameraDirectorPermitsDirectControl(void) (76 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); lwz 0,0x4(3); li 31,1; cmpwi 0,0; beq 0f; lwz 3,0x0(3); bl _s80206134_0; cmpwi 3,0; beq 1f; 0:; li 31,0; 1:; mr 3,31; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s80206134_0();
extern "C" void f_80206134() {}
