// 0x802BCCA0 EAStringC::Delete(int, (336 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 26,0x8(1); stw 0,0x24(1); mr 27,4; mr 26,3; cmpwi 5,0; add 28,27,5; ble 0f; cmpwi 28,0; bgt 2f; 0:; lwz 4,0x0(26); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 1f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s802BCCA0_0; 1:; lis 11,-32700; li 3,0; addi 0,11,-6476; stw 0,0x0(26); lhz 9,-6476(11); addi 9,9,1; sth 9,-6476(11); b 7f; 2:; cmpwi 27,0; bge 3f; li 27,0; 3:; lwz 29,0x0(26); lhz 3,0x2(29); cmpw 28,3; blt 4f; mr 28,3; 4:; cmpwi 27,0; bne 5f; subf 31,28,3; mr 5,28; mr 3,26; mr 4,31; mr 6,31; li 7,1; mr 8,31; bl _s802BCCA0_1; mr 3,31; b 7f; 5:; cmpw 28,3; beq 6f; subf 30,28,3; addi 29,29,8; add 31,27,30; mr 3,26; mr 4,31; li 5,0; mr 6,27; li 7,0; mr 8,31; bl _s802BCCA0_2; lwz 3,0x0(26); add 4,29,28; addi 5,30,1; addi 3,3,8; add 3,3,27; crxor 6,6,6; bl _s802BCCA0_3; mr 3,31; b 7f; 6:; mr 3,26; mr 4,27; li 5,0; mr 6,27; li 7,1; mr 8,27; bl _s802BCCA0_4; mr 3,27; 7:; lwz 0,0x24(1); mtspr 8,0; lmw 26,0x8(1); addi 1,1,32"
extern "C" void _s802BCCA0_0();
extern "C" void _s802BCCA0_1();
extern "C" void _s802BCCA0_2();
extern "C" void _s802BCCA0_3();
extern "C" void _s802BCCA0_4();
extern "C" void f_802BCCA0() {}
