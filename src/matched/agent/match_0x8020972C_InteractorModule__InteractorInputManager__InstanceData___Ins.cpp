// 0x8020972C InteractorModule::InteractorInputManager::InstanceData::~InstanceData(void) (152 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; mr 30,4; bl _s8020972C_0; lwz 0,0x4(31); lwz 9,0x0(31); cmpw 9,0; beq 1f; 0:; addi 9,9,12; cmpw 9,0; bne 0b; 1:; lwz 3,0x0(31); cmpwi 3,0; beq 3f; lwz 0,0xc(31); lis 9,-21846; ori 9,9,43691; subf 0,3,0; mullw 0,0,9; srawi 0,0,2; mulli 4,0,12; cmplwi 4,128; ble 2f; bl _s8020972C_1; b 3f; 2:; bl _s8020972C_2; 3:; andi. 0,30,1; beq 4f; mr 3,31; bl _s8020972C_3; 4:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8020972C_0();
extern "C" void _s8020972C_1();
extern "C" void _s8020972C_2();
extern "C" void _s8020972C_3();
extern "C" void f_8020972C() {}
