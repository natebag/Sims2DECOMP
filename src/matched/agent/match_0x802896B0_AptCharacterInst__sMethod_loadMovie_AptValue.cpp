// 0x802896B0 AptCharacterInst::sMethod_loadMovie(AptValue (488 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 28,0x20(1); stw 0,0x34(1); lis 9,-32694; lis 10,-32700; lwz 11,-16032(9); mr 29,3; addi 9,9,-16032; addi 4,1,8; lwz 0,0x8(9); rlwinm 11,11,2,0,29; lhz 9,-6476(10); mr 28,4; add 11,11,0; lwz 3,-4(11); addi 9,9,1; addi 0,10,-6476; sth 9,-6476(10); stw 0,0x8(1); bl _s802896B0_0; lwz 9,0x8(1); lhz 30,0x2(9); cmpwi 30,0; beq 3f; addi 11,9,8; addi 0,30,-1; lbzx 9,11,0; extsb 9,9; cmpwi 9,102; beq 0f; cmpwi 9,70; bne 6f; 0:; addi 0,30,-2; lbzx 9,11,0; extsb 9,9; cmpwi 9,119; beq 1f; cmpwi 9,87; bne 6f; 1:; addi 0,30,-3; lbzx 9,11,0; extsb 9,9; cmpwi 9,115; beq 2f; cmpwi 9,83; bne 6f; 2:; addi 0,30,-4; lbzx 9,11,0; cmpwi 9,46; bne 6f; 3:; lis 10,-32700; lwz 8,0x8(1); lhz 11,-6476(10); addi 0,10,-6476; stw 0,0x10(1); addi 11,11,1; sth 11,-6476(10); lhz 9,0x0(8); addi 9,9,1; sth 9,0x0(8); lwz 4,0x10(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 4f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s802896B0_1; 4:; lwz 0,0x8(1); cmpwi 30,3; addi 31,1,16; stw 0,0x10(1); ble 5f; addi 4,30,-4; mr 3,31; li 5,4; bl _s802896B0_2; 5:; mr 3,29; mr 4,28; bl _s802896B0_3; lwz 11,0x8(1); mr 4,31; lwz 3,-22996(13); addi 5,1,24; stw 11,0x18(1); lhz 9,0x0(11); addi 9,9,1; sth 9,0x0(11); bl _s802896B0_4; lwz 4,0x10(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 6f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s802896B0_5; 6:; lwz 4,0x8(1); lwz 31,-22936(13); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 7f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s802896B0_6; 7:; mr 3,31; lwz 0,0x34(1); mtspr 8,0; lmw 28,0x20(1); addi 1,1,48"
extern "C" void _s802896B0_0();
extern "C" void _s802896B0_1();
extern "C" void _s802896B0_2();
extern "C" void _s802896B0_3();
extern "C" void _s802896B0_4();
extern "C" void _s802896B0_5();
extern "C" void _s802896B0_6();
extern "C" void f_802896B0() {}
