// 0x8022AE6C EIPortalPointLight::IsEnabled(void) (176 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stw 31,0x14(1); stw 0,0x1c(1); mr 31,3; addi 5,1,8; lwz 0,0x1c(31); addi 6,1,10; cmpwi 0,0; beq 0f; lwz 3,0x28(31); li 4,0; mtspr 8,0; blrl; b 1f; 0:; sth 0,0x8(1); sth 0,0xa(1); 1:; lwz 0,0x20(31); addi 5,1,12; addi 6,1,14; cmpwi 0,0; beq 2f; lwz 3,0x24(31); li 4,0; mtspr 8,0; blrl; b 3f; 2:; li 0,-1; sth 0,0xc(1); sth 0,0xe(1); 3:; lha 9,0xe(1); li 3,0; lha 0,0xa(1); cmpw 9,0; beq 4f; lwz 0,0x88(31); cmpwi 0,0; beq 4f; li 3,1; 4:; lwz 0,0x1c(1); mtspr 8,0; lwz 31,0x14(1); addi 1,1,24"
extern "C" void f_8022AE6C() {}
