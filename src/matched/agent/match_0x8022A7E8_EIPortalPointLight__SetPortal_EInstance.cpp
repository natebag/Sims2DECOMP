// 0x8022A7E8 EIPortalPointLight::SetPortal(EInstance (60 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); stw 4,0xd4(3); stw 5,0xd0(3); lwz 9,0x0(3); lha 0,0x58(9); lwz 9,0x5c(9); add 3,3,0; mtspr 8,9; blrl; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void f_8022A7E8() {}
