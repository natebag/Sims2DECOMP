// 0x801C294C M2MTarget::UpdateSelection(int) (120 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); cmpwi 4,0; lwz 11,0x18c(3); bge 0f; addi 0,11,-1; cmpwi 0,0; stw 0,0x18c(3); bge 1f; lwz 9,0x188(3); addi 9,9,-1; stw 9,0x18c(3); b 1f; 0:; ble 1f; lwz 9,0x188(3); addi 0,11,1; stw 0,0x18c(3); cmpw 0,9; blt 1f; li 0,0; stw 0,0x18c(3); 1:; lwz 0,0x18c(3); cmpw 11,0; beq 2f; bl _s801C294C_0; 2:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s801C294C_0();
extern "C" void f_801C294C() {}
