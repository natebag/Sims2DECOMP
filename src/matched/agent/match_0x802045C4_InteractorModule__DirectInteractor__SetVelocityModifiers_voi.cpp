// 0x802045C4 InteractorModule::DirectInteractor::SetVelocityModifiers(void) (92 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; lwz 11,0x70(31); cmpwi 11,0; beq 0f; lwz 9,0x4(11); lha 3,0x188(9); lwz 0,0x18c(9); add 3,11,3; mtspr 8,0; blrl; mr 30,3; lwz 3,0x4(31); bl _s802045C4_0; stfs f1,0xb8(30); 0:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s802045C4_0();
extern "C" void f_802045C4() {}
