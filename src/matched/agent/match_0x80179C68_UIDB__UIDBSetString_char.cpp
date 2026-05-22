// 0x80179C68 UIDB::UIDBSetString(char (156 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); lwz 0,-31520(13); mr 9,3; mr 29,4; li 3,0; cmpwi 0,0; beq 2f; mr 3,9; li 4,115; bl _s80179C68_0; mr. 30,3; beq 1f; mr 3,29; bl _s80179C68_1; mr 31,3; cmpwi 31,63; ble 0f; li 31,63; 0:; lwz 3,0x8(30); mr 4,29; mr 5,31; bl _s80179C68_2; lwz 3,0x8(30); add 0,31,31; lis 4,-32706; add 3,3,0; addi 4,4,9472; bl _s80179C68_3; li 3,1; b 2f; 1:; li 3,0; 2:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s80179C68_0();
extern "C" void _s80179C68_1();
extern "C" void _s80179C68_2();
extern "C" void _s80179C68_3();
extern "C" void f_80179C68() {}
