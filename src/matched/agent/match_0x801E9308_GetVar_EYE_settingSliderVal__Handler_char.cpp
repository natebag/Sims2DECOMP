// 0x801E9308 GetVar_EYE_settingSliderVal::Handler(char (72 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lwz 0,0xc(3); mr 30,4; mtspr 8,0; blrl; lis 4,-32704; mr 3,30; addi 4,4,-30816; creqv 6,6,6; bl _s801E9308_0; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s801E9308_0();
extern "C" void f_801E9308() {}
