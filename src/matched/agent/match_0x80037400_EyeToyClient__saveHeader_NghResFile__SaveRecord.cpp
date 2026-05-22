// 0x80037400 EyeToyClient::saveHeader(NghResFile::SaveRecord (172 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); lis 30,-32697; mr 31,3; addi 3,30,23352; li 4,0; li 5,28; bl _s80037400_0; li 0,28; lis 9,-32702; stw 0,0x5b38(30); addi 9,9,15808; li 0,5; lis 11,-32697; mtspr 9,0; addi 9,9,11; addi 11,11,23356; li 10,0; 0:; lbz 0,0x0(9); addi 9,9,12; stbx 0,11,10; addi 10,10,1; bdnz 0b; lis 29,-32697; bl _s80037400_1; addi 30,29,23352; stfs f1,0xc(30); bl _s80037400_2; stfs f1,0x10(30); bl _s80037400_3; stfs f1,0x14(30); bl _s80037400_4; stfs f1,0x18(30); stw 30,0x4(31); lwz 0,0x5b38(29); stw 0,0x0(31); lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s80037400_0();
extern "C" void _s80037400_1();
extern "C" void _s80037400_2();
extern "C" void _s80037400_3();
extern "C" void _s80037400_4();
extern "C" void f_80037400() {}
