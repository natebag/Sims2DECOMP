// 0x8020AA6C InteractorModule::InteractorInputManager::InstanceData::CloseSession(void) (124 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lwz 0,0x14(31); cmpwi 0,-1; beq 0f; lwz 4,0x18(31); lwz 3,-26524(13); bl _s8020AA6C_0; lwz 4,0x14(31); bl _s8020AA6C_1; li 0,-1; stw 0,0x14(31); 0:; lwz 11,0x0(31); lwz 0,0x4(31); mr 9,11; cmpw 11,0; beq 2f; 1:; addi 9,9,12; cmpw 9,0; bne 1b; 2:; li 0,0; stw 11,0x4(31); stw 0,0x1c(31); lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s8020AA6C_0();
extern "C" void _s8020AA6C_1();
extern "C" void f_8020AA6C() {}
