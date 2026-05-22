// 0x801FC748 PDATarget::SetupMoney(void) (252 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-560(1); mfspr 0,8; mfcr 12; stmw 26,0x218(1); stw 0,0x234(1); stw 12,0x214(1); lis 9,-32697; li 28,1; lwz 0,0x5c70(9); cmpwi 0,0; bne 0f; li 28,0; 0:; li 29,0; cmpw 29,28; bgt 5f; lis 26,-32704; lis 27,-32704; 1:; lwz 3,-21496(13); cmpwi 3,0; beq 4f; lwz 9,0x0(3); li 4,1; cmpwi 4,29,0; lha 0,0xa0(9); addi 11,9,160; add 3,3,0; bne cr4,2f; li 4,0; 2:; lwz 0,0x4(11); addi 31,1,8; mtspr 8,0; blrl; mr 30,3; addi 4,31,8; li 5,256; mr 3,31; bl _s801FC748_0; mr 3,30; mr 4,31; li 5,0; bl _s801FC748_1; bne cr4,3f; mr 3,31; bl _s801FC748_2; mr 4,3; addi 3,26,-23456; bl _s801FC748_3; b 4f; 3:; mr 3,31; bl _s801FC748_4; mr 4,3; addi 3,27,-23444; bl _s801FC748_5; 4:; addi 29,29,1; cmpw 29,28; ble 1b; 5:; lwz 0,0x234(1); lwz 12,0x214(1); mtspr 8,0; lmw 26,0x218(1); mtcrf 8,12; addi 1,1,560"
extern "C" void _s801FC748_0();
extern "C" void _s801FC748_1();
extern "C" void _s801FC748_2();
extern "C" void _s801FC748_3();
extern "C" void _s801FC748_4();
extern "C" void _s801FC748_5();
extern "C" void f_801FC748() {}
