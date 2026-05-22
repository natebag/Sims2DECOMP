// 0x80299500 AptDisplayListState::insert(AptCIH (256 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 31,5; mr 29,4; mr 3,31; li 28,0; bl _s80299500_0; li 30,0; cmpwi 3,13; bne 0f; mr 3,31; bl _s80299500_1; subfic 0,3,0; adde 30,0,3; 0:; cmpwi 30,0; bne 2f; mr 3,31; li 30,0; bl _s80299500_2; cmpwi 3,18; bne 1f; mr 3,31; bl _s80299500_3; subfic 0,3,0; adde 30,0,3; 1:; cmpwi 30,0; beq 3f; 2:; li 28,1; 3:; cmpwi 28,0; bne 4f; mr 3,31; bl _s80299500_4; cmpwi 3,14; bne 4f; mr 3,31; bl _s80299500_5; 4:; lwz 0,0x54(29); lis 4,-32704; lwz 9,0x8(31); lis 5,-32704; stw 29,0x50(31); addi 4,4,29732; stw 0,0x54(31); addi 5,5,29796; li 6,477; lha 3,0x8(9); lwz 0,0xc(9); add 3,31,3; mtspr 8,0; blrl; lwz 9,0x54(31); cmpwi 9,0; beq 5f; stw 31,0x50(9); 5:; lwz 9,0x50(31); mr 3,31; stw 31,0x54(9); lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s80299500_0();
extern "C" void _s80299500_1();
extern "C" void _s80299500_2();
extern "C" void _s80299500_3();
extern "C" void _s80299500_4();
extern "C" void _s80299500_5();
extern "C" void f_80299500() {}
