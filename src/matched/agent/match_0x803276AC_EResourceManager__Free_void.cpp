// 0x803276AC EResourceManager::Free(void (80 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 11,3; mr. 31,4; beq 0f; lwz 9,0xd1c(11); lha 3,0x30(9); lwz 0,0x34(9); add 3,11,3; mtspr 8,0; blrl; mr 4,31; bl _s803276AC_0; 0:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s803276AC_0();
extern "C" void f_803276AC() {}
