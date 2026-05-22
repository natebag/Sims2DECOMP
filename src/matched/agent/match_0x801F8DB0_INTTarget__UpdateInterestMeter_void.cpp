// 0x801F8DB0 INTTarget::UpdateInterestMeter(void) (220 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; lwz 0,0x88(31); cmpwi 0,0; bne 0f; lis 30,-32697; lwz 4,0x98(31); addi 3,30,24012; bl _s801F8DB0_0; cmpwi 3,0; beq 2f; lwz 4,0x98(31); addi 3,30,24012; bl _s801F8DB0_1; lwz 9,0x4(3); lha 0,0x330(9); lwz 9,0x334(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; beq 2f; mr 3,31; bl _s801F8DB0_2; b 2f; 0:; lwz 0,0x8c(31); cmpwi 0,0; bne 2f; lis 30,-32697; lwz 4,0x98(31); addi 3,30,24012; bl _s801F8DB0_3; cmpwi 3,0; beq 1f; lwz 4,0x98(31); addi 3,30,24012; bl _s801F8DB0_4; lwz 9,0x4(3); lha 0,0x330(9); lwz 9,0x334(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; bne 2f; 1:; mr 3,31; bl _s801F8DB0_5; 2:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s801F8DB0_0();
extern "C" void _s801F8DB0_1();
extern "C" void _s801F8DB0_2();
extern "C" void _s801F8DB0_3();
extern "C" void _s801F8DB0_4();
extern "C" void _s801F8DB0_5();
extern "C" void f_801F8DB0() {}
