// 0x802E317C EEngine::PostFrameUpdate(void) (128 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; lwz 3,-26392(13); bl _s802E317C_0; lwz 11,-26392(13); lwz 9,0x0(11); lwz 0,0x3c(9); lha 3,0x38(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,-26532(13); addi 4,30,32; lfs f13,-26780(13); lwz 9,0x0(11); lfs f0,-26784(13); lha 3,0x28(9); lwz 0,0x2c(9); add 3,11,3; stfs f13,-26776(13); mtspr 8,0; stfs f0,-26780(13); blrl; stfs f1,-26784(13); lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s802E317C_0();
extern "C" void f_802E317C() {}
