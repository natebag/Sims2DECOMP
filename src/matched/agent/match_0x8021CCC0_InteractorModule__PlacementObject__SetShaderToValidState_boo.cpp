// 0x8021CCC0 InteractorModule::PlacementObject::SetShaderToValidState(bool) (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); lwz 11,0x0(3); mr 31,4; cmpwi 11,0; beq 0f; lwz 9,0x4(11); lha 3,0x520(9); lwz 0,0x524(9); add 3,11,3; mtspr 8,0; blrl; mr 4,31; bl _s8021CCC0_0; 0:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s8021CCC0_0();
extern "C" void f_8021CCC0() {}
