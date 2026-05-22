// 0x802294AC EInstance::ResetLocation(void) (124 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stw 31,0x14(1); stw 0,0x1c(1); mr 31,3; lwz 0,0x1c(31); cmpwi 0,0; beq 0f; lwz 3,0x28(31); li 4,1; addi 5,1,8; addi 6,1,10; mtspr 8,0; blrl; b 1f; 0:; sth 0,0x8(1); sth 0,0xa(1); 1:; lwz 0,0x20(31); cmpwi 0,0; beq 2f; lwz 3,0x24(31); li 4,1; addi 5,1,8; addi 6,1,10; mtspr 8,0; blrl; 2:; lwz 0,0x1c(1); mtspr 8,0; lwz 31,0x14(1); addi 1,1,24"
extern "C" void f_802294AC() {}
