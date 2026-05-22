// 0x8029374C AptCIH::GetMovieclipInfo(AptMovieclipInformation (364 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 30,3; mr 31,4; lwz 0,0x0(30); rlwinm 0,0,0,25,31; cmpwi 0,15; beq 4f; bgt 0f; cmpwi 0,13; beq 2f; bgt 3f; cmpwi 0,12; beq 1f; b 8f; 0:; cmpwi 0,17; beq 6f; blt 5f; cmpwi 0,18; beq 7f; b 8f; 1:; lwz 9,0x18(31); addi 9,9,1; stw 9,0x18(31); b 8f; 2:; lwz 9,0x4(31); addi 9,9,1; stw 9,0x4(31); b 8f; 3:; lwz 9,0x8(31); addi 9,9,1; stw 9,0x8(31); lwz 3,0x4c(30); addi 3,3,28; bl _s8029374C_0; mr 4,31; bl _s8029374C_1; b 8f; 4:; lwz 9,0x10(31); addi 9,9,1; stw 9,0x10(31); b 8f; 5:; lwz 9,0xc(31); addi 9,9,1; stw 9,0xc(31); b 8f; 6:; lwz 9,0x14(31); addi 9,9,1; stw 9,0x14(31); b 8f; 7:; lwz 9,0x0(31); addi 9,9,1; stw 9,0x0(31); 8:; mr 3,30; li 28,0; bl _s8029374C_2; li 29,0; cmpwi 3,13; bne 9f; mr 3,30; bl _s8029374C_3; subfic 0,3,0; adde 29,0,3; 9:; cmpwi 29,0; bne 11f; mr 3,30; li 29,0; bl _s8029374C_4; cmpwi 3,18; bne 10f; mr 3,30; bl _s8029374C_5; subfic 0,3,0; adde 29,0,3; 10:; cmpwi 29,0; beq 12f; 11:; li 28,1; 12:; cmpwi 28,0; beq 13f; lwz 3,0x4c(30); addi 3,3,36; bl _s8029374C_6; mr 4,31; bl _s8029374C_7; 13:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s8029374C_0();
extern "C" void _s8029374C_1();
extern "C" void _s8029374C_2();
extern "C" void _s8029374C_3();
extern "C" void _s8029374C_4();
extern "C" void _s8029374C_5();
extern "C" void _s8029374C_6();
extern "C" void _s8029374C_7();
extern "C" void f_8029374C() {}
