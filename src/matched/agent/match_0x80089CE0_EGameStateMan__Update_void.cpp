// 0x80089CE0 EGameStateMan::Update(void) (92 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); lis 9,-32697; mr 31,3; lwz 3,0x5ee0(9); cmpwi 3,0; beq 0f; bl _s80089CE0_0; 0:; lwz 9,0x0(31); lwz 10,0x0(9); lwz 11,0x8(10); lha 3,0x18(11); lwz 0,0x1c(11); add 3,10,3; mtspr 8,0; blrl; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s80089CE0_0();
extern "C" void f_80089CE0() {}
