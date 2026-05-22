// 0x8020450C InteractorModule::DirectInteractor::UpdateControlStatus(void) (184 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; li 0,1; lwz 9,0x4(31); li 30,1; stw 0,0x64(31); cmpwi 9,0; beq 0f; lwz 3,0x0(31); bl _s8020450C_0; cmpwi 3,0; beq 1f; 0:; li 30,0; 1:; cmpwi 30,0; bne 2f; li 0,3; stw 0,0x64(31); b 4f; 2:; lwz 30,0x2c(31); cmpwi 30,0; beq 3f; li 0,2; stw 0,0x64(31); b 4f; 3:; lwz 11,0x70(31); cmpwi 11,0; beq 4f; lwz 9,0x4(11); lha 3,0x188(9); lwz 0,0x18c(9); add 3,11,3; mtspr 8,0; blrl; lwz 9,0x2c(3); addi 9,9,-9; cmplwi 9,5; ble 4f; stw 30,0x64(31); 4:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8020450C_0();
extern "C" void f_8020450C() {}
