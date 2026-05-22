// 0x802BE64C EAStringC::ChangeBuffer(unsigned (356 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 23,0xc(1); stw 0,0x34(1); mr 31,3; mr 28,5; lwz 3,0x0(31); mr 25,6; mr 24,7; mr 27,8; lhz 0,0x0(3); cmpwi 0,1; bne 1f; lhz 0,0x4(3); cmplw 4,0; bgt 1f; cmpwi 28,0; beq 0f; addi 3,3,8; mr 5,25; add 4,3,28; bl _s802BE64C_0; 0:; lwz 11,0x0(31); li 0,0; cmpwi 24,0; sth 27,0x2(11); lwz 9,0x0(31); sth 0,0x6(9); beq 4f; lwz 9,0x0(31); addi 9,9,8; stbx 0,9,27; b 4f; 1:; lwz 29,0x0(31); cmpwi 4,0; addi 26,29,8; beq 2f; rlwinm 30,4,29,3,31; lwz 3,-23020(13); add 30,4,30; li 23,0; addi 30,30,12; rlwinm 30,30,0,0,29; mr 4,30; bl _s802BE64C_1; stw 3,0x0(31); li 0,1; sth 0,0x0(3); addi 30,30,-9; add 4,26,28; mr 5,25; lwz 9,0x0(31); sth 30,0x4(9); lwz 11,0x0(31); sth 27,0x2(11); lwz 9,0x0(31); sth 23,0x6(9); lwz 3,0x0(31); addi 3,3,8; crxor 6,6,6; bl _s802BE64C_2; cmpwi 24,0; beq 3f; lwz 9,0x0(31); addi 9,9,8; stbx 23,9,27; b 3f; 2:; lis 11,-32700; addi 0,11,-6476; stw 0,0x0(31); lhz 9,-6476(11); addi 9,9,1; sth 9,-6476(11); 3:; lhz 9,0x0(29); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(29); cmpwi 0,0; bne 4f; lhz 5,0x4(29); mr 4,29; lwz 3,-23020(13); addi 5,5,9; bl _s802BE64C_3; 4:; lwz 0,0x34(1); mtspr 8,0; lmw 23,0xc(1); addi 1,1,48"
extern "C" void _s802BE64C_0();
extern "C" void _s802BE64C_1();
extern "C" void _s802BE64C_2();
extern "C" void _s802BE64C_3();
extern "C" void f_802BE64C() {}
