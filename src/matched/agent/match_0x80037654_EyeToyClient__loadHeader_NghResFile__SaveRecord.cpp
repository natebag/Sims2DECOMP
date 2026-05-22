// 0x80037654 EyeToyClient::loadHeader(NghResFile::SaveRecord (180 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); lis 29,-32697; mr 30,3; addi 31,29,23352; li 4,0; mr 3,31; li 5,28; bl _s80037654_0; li 0,28; stw 0,0x5b38(29); lwz 10,0x4(30); cmpwi 10,0; beq 0f; lwz 8,0x0(10); cmpwi 8,28; bne 0f; lwz 9,0x4(10); lwz 11,0x8(10); lwz 0,0xc(10); stw 8,0x5b38(29); stw 0,0xc(31); stw 9,0x4(31); stw 11,0x8(31); lfs f1,0xc(31); lwz 11,0x18(10); lwz 0,0x10(10); lwz 9,0x14(10); stw 0,0x10(31); stw 9,0x14(31); stw 11,0x18(31); bl _s80037654_1; lfs f1,0x10(31); bl _s80037654_2; lfs f1,0x14(31); bl _s80037654_3; lfs f1,0x18(31); bl _s80037654_4; 0:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s80037654_0();
extern "C" void _s80037654_1();
extern "C" void _s80037654_2();
extern "C" void _s80037654_3();
extern "C" void _s80037654_4();
extern "C" void f_80037654() {}
