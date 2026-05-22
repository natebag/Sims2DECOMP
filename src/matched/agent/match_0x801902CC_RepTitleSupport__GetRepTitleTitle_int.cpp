// 0x801902CC RepTitleSupport::GetRepTitleTitle(int) (408 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 31,3; cmplwi 4,1; ble 0f; li 4,0; 0:; lis 9,-32697; rlwinm 0,4,2,0,29; addi 28,9,24012; addi 11,28,188; lwzx 4,11,0; cmpwi 4,0; beq 7f; lwz 9,0x4(4); lwz 29,-21476(13); lha 3,0x1b0(9); lwz 9,0x1b4(9); lwz 30,0x0(29); add 3,4,3; mtspr 8,9; lha 0,0xb8(30); addi 30,30,184; add 29,29,0; blrl; lwz 0,0x4(30); mr 4,3; mr 3,29; mtspr 8,0; blrl; mr. 29,3; beq 7f; mr 3,29; bl _s801902CC_0; mr 4,3; mr 3,28; bl _s801902CC_1; mr. 30,3; beq 7f; mr 3,29; bl _s801902CC_2; mr 28,3; mr 3,29; bl _s801902CC_3; mr 10,3; lwz 0,0x14(30); lwz 3,0xc(30); li 9,0; cmpwi 3,0; beq 1f; cmpw cr7,28,3; cror 31,30,29; mfcr 9; rlwinm 9,9,0,31,31; 1:; li 11,0; cmpwi 0,0; beq 2f; cmpw cr7,10,0; cror 31,30,29; mfcr 11; rlwinm 11,11,0,31,31; 2:; cmpwi 7,9,0; beq cr7,3f; cmpwi 11,0; beq 5f; subf 9,3,28; subf 0,0,10; cmpw 9,0; bgt 6f; b 4f; 3:; cmpwi 11,0; beq 5f; 4:; lwz 0,0x18(30); stw 0,0x0(31); b 10f; 5:; beq cr7,8f; 6:; lwz 0,0x10(30); stw 0,0x0(31); b 10f; 7:; lis 3,-32697; li 4,0; addi 3,3,24012; bl _s801902CC_4; mr. 30,3; beq 9f; 8:; lwz 0,0x8(30); stw 0,0x0(31); b 10f; 9:; lis 5,-32705; lis 4,-32697; addi 4,4,24012; addi 5,5,-17480; mr 3,31; crxor 6,6,6; bl _s801902CC_5; 10:; mr 3,31; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s801902CC_0();
extern "C" void _s801902CC_1();
extern "C" void _s801902CC_2();
extern "C" void _s801902CC_3();
extern "C" void _s801902CC_4();
extern "C" void _s801902CC_5();
extern "C" void f_801902CC() {}
