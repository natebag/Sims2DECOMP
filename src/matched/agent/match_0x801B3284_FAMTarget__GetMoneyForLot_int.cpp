// 0x801B3284 FAMTarget::GetMoneyForLot(int) (144 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-328(1); mfspr 0,8; stmw 29,0x13c(1); stw 0,0x14c(1); li 0,0; addi 30,1,8; stw 0,0x8(1); mr 29,4; li 9,-1; addi 4,1,36; li 5,128; addi 3,1,28; stw 0,0xc(30); stw 9,0x10(30); stw 0,0x4(30); stw 0,0x8(30); bl _s801B3284_0; lwz 11,-21476(13); lwz 9,0x0(11); lwz 0,0x194(9); lha 3,0x190(9); mtspr 8,0; add 3,11,3; blrl; mr 9,3; lwz 4,-32056(13); mr 5,29; mr 6,30; stw 29,0x70(9); bl _s801B3284_1; lwz 3,0x14(1); lwz 0,0x14c(1); mtspr 8,0; lmw 29,0x13c(1); addi 1,1,328"
extern "C" void _s801B3284_0();
extern "C" void _s801B3284_1();
extern "C" void f_801B3284() {}
