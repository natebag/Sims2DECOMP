// 0x802E1918 ENgcFile::Creator(EFile (196 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 28,6; mr 29,7; mr 30,4; bl _s802E1918_0; li 5,0; li 4,120; bl _s802E1918_1; bl _s802E1918_2; mr 31,3; li 9,0; li 0,1; stw 9,0x68(31); stw 0,0x74(31); mr 3,30; stw 9,0x70(31); addi 4,31,44; bl _s802E1918_3; cmpwi 3,0; bne 1f; cmpwi 31,0; beq 0f; lwz 9,0x28(31); li 4,3; lha 3,0x8(9); lwz 0,0xc(9); add 3,31,3; mtspr 8,0; blrl; 0:; li 3,0; b 2f; 1:; lwz 9,0x60(31); lis 0,-32768; stw 29,0xc(31); mr 3,31; stw 28,0x10(31); mr 4,30; stw 0,0x8(31); stw 9,0x14(31); bl _s802E1918_4; mr 3,31; 2:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s802E1918_0();
extern "C" void _s802E1918_1();
extern "C" void _s802E1918_2();
extern "C" void _s802E1918_3();
extern "C" void _s802E1918_4();
extern "C" void f_802E1918() {}
