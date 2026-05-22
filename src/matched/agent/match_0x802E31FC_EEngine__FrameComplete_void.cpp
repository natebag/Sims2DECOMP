// 0x802E31FC EEngine::FrameComplete(void) (60 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 11,-25912(13); addi 4,3,52; lwz 9,0x338(11); lha 3,0x38(9); lwz 0,0x3c(9); add 3,11,3; mtspr 8,0; blrl; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void f_802E31FC() {}
