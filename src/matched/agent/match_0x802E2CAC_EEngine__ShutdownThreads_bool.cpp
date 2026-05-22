// 0x802E2CAC EEngine::ShutdownThreads(bool) (176 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lwz 11,-26524(13); mr 31,3; mr 30,4; cmpwi 11,0; beq 0f; lwz 9,0x20(11); lha 3,0x20(9); lwz 0,0x24(9); add 3,11,3; mtspr 8,0; blrl; 0:; lwz 11,-26564(13); cmpwi 11,0; beq 1f; lwz 9,0x0(11); lha 3,0x18(9); lwz 0,0x1c(9); add 3,11,3; mtspr 8,0; blrl; 1:; bl _s802E2CAC_0; lwz 9,0x0(31); lha 3,0xa0(9); lwz 0,0xa4(9); add 3,31,3; mtspr 8,0; blrl; cmpwi 30,0; beq 2f; lwz 9,0x0(31); lha 3,0xa8(9); lwz 0,0xac(9); add 3,31,3; mtspr 8,0; blrl; 2:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s802E2CAC_0();
extern "C" void f_802E2CAC() {}
