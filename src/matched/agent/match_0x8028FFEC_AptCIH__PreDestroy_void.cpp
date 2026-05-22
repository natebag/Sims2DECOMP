// 0x8028FFEC AptCIH::PreDestroy(void) (80 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 11,0x4c(3); cmpwi 11,0; beq 0f; lis 0,-17747; ori 0,0,61453; cmpw 11,0; beq 0f; lwz 9,0x14(11); lha 3,0x8(9); lwz 0,0xc(9); add 3,11,3; mtspr 8,0; blrl; 0:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void f_8028FFEC() {}
