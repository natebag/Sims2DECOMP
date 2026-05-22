// 0x802AFC14 AptTextFormat::AptTextFormat(AptValue (552 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-64(1); mfspr 0,8; stfd f31,0x38(1); stmw 24,0x18(1); stw 0,0x44(1); mr 29,3; mr 25,4; fmr f31,f1; mr 30,5; mr 28,6; mr 27,7; mr 26,8; lwz 24,0x48(1); li 4,36; bl _s802AFC14_0; addi 31,29,36; lis 9,-32703; li 4,8; addi 9,9,8984; addi 3,29,12; stw 9,0x8(29); bl _s802AFC14_1; li 0,0; lis 9,-32703; stb 0,0x20(29); addi 9,9,21120; stw 9,0x8(29); mr 3,31; lwz 0,0x20(29); rlwinm 0,0,0,10,7; stw 0,0x20(29); bl _s802AFC14_2; li 0,2; stfs f31,0x4(31); stw 30,0x8(31); cmpwi 28,0; stw 0,0x10(31); bne 0f; lis 0,1; ori 0,0,2; stw 0,0x10(31); 0:; cmpwi 28,1; bne 1f; lwz 0,0x10(31); oris 0,0,1; ori 0,0,1; stw 0,0x10(31); 1:; cmpwi 27,0; bne 2f; lwz 0,0x10(31); oris 0,0,16; stw 0,0x10(31); 2:; cmpwi 27,1; bne 3f; lwz 0,0x10(31); oris 0,0,16; ori 0,0,16; stw 0,0x10(31); 3:; cmpwi 26,0; bne 4f; lwz 0,0x10(31); oris 0,0,256; stw 0,0x10(31); 4:; cmpwi 26,1; bne 5f; lwz 0,0x10(31); oris 0,0,256; ori 0,0,256; stw 0,0x10(31); 5:; lwz 0,0x54(1); mr 3,25; stw 0,0x14(31); lwz 0,0x4c(1); stw 0,0x18(31); lwz 9,0x50(1); stw 9,0x1c(31); bl _s802AFC14_3; cmpwi 3,0; bne 6f; mr 3,25; mr 4,31; bl _s802AFC14_4; 6:; mr 3,24; bl _s802AFC14_5; mr. 30,3; bne 12f; addi 3,1,8; bl _s802AFC14_6; addi 4,1,8; mr 3,24; bl _s802AFC14_7; lis 4,-32703; addi 3,1,8; addi 4,4,3968; bl _s802AFC14_8; cmpwi 3,0; bne 7f; lis 4,-32703; addi 3,1,8; addi 4,4,3976; bl _s802AFC14_9; cmpwi 3,0; beq 8f; 7:; stw 30,0xc(31); b 11f; 8:; lis 4,-32703; addi 3,1,8; addi 4,4,3984; bl _s802AFC14_10; cmpwi 3,0; beq 9f; li 0,2; b 10f; 9:; lis 4,-32703; addi 3,1,8; addi 4,4,3992; bl _s802AFC14_11; cmpwi 3,0; li 0,3; beq 10f; li 0,1; 10:; stw 0,0xc(31); 11:; addi 3,1,8; li 4,2; bl _s802AFC14_12; b 13f; 12:; li 0,3; stw 0,0xc(31); 13:; lis 9,-32703; mr 3,29; addi 9,9,4912; stw 9,0x8(29); lwz 0,0x44(1); mtspr 8,0; lmw 24,0x18(1); lfd f31,0x38(1); addi 1,1,64"
extern "C" void _s802AFC14_0();
extern "C" void _s802AFC14_1();
extern "C" void _s802AFC14_2();
extern "C" void _s802AFC14_3();
extern "C" void _s802AFC14_4();
extern "C" void _s802AFC14_5();
extern "C" void _s802AFC14_6();
extern "C" void _s802AFC14_7();
extern "C" void _s802AFC14_8();
extern "C" void _s802AFC14_9();
extern "C" void _s802AFC14_10();
extern "C" void _s802AFC14_11();
extern "C" void _s802AFC14_12();
extern "C" void f_802AFC14() {}
