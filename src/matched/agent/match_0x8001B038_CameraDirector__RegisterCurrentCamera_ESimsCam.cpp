// 0x8001B038 CameraDirector::RegisterCurrentCamera(ESimsCam (64 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); mr. 4,4; beq 0f; lwz 0,0x170(3); cmpw 0,4; bne 1f; 0:; cmpwi 5,0; beq 2f; 1:; stw 4,0x170(3); bl _s8001B038_0; 2:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s8001B038_0();
extern "C" void f_8001B038() {}
