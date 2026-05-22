// 0x8001D5F8 CameraDirector::StartAnim(AnimRef (76 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,4; mr 31,3; lwz 4,0x0(30); bl _s8001D5F8_0; cmpwi 3,0; beq 0f; stw 30,0x220(31); li 3,1; b 1f; 0:; li 3,0; 1:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8001D5F8_0();
extern "C" void f_8001D5F8() {}
