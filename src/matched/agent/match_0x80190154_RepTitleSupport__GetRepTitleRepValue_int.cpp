// 0x80190154 RepTitleSupport::GetRepTitleRepValue(int) (208 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); cmplwi 3,1; ble 0f; li 3,0; 0:; lis 9,-32697; rlwinm 0,3,2,0,29; addi 31,9,24012; addi 11,31,188; lwzx 11,11,0; cmpwi 11,0; beq 1f; lwz 9,0x4(11); lwz 29,-21476(13); lha 3,0x1b0(9); lwz 9,0x1b4(9); lwz 30,0x0(29); add 3,11,3; mtspr 8,9; lha 0,0xb8(30); addi 30,30,184; add 29,29,0; blrl; lwz 0,0x4(30); mr 4,3; mr 3,29; mtspr 8,0; blrl; mr. 3,3; beq 1f; bl _s80190154_0; mr 4,3; mr 3,31; bl _s80190154_1; mr. 3,3; bne 2f; 1:; lis 3,-32697; li 4,0; addi 3,3,24012; bl _s80190154_2; mr. 3,3; bne 2f; li 3,0; b 3f; 2:; lwz 3,0x0(3); 3:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s80190154_0();
extern "C" void _s80190154_1();
extern "C" void _s80190154_2();
extern "C" void f_80190154() {}
