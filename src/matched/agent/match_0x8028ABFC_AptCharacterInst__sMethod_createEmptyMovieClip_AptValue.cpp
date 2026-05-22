// 0x8028ABFC AptCharacterInst::sMethod_createEmptyMovieClip(AptValue (440 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stmw 26,0x20(1); stw 0,0x3c(1); mr 31,3; cmpwi 4,2; beq 0f; lwz 3,-22936(13); b 6f; 0:; lis 9,-32694; addi 27,1,24; lwz 11,-16032(9); li 29,0; addi 9,9,-16032; lwz 0,0x8(9); addi 9,11,-1; rlwinm 9,9,2,0,29; rlwinm 11,11,2,0,29; add 9,9,0; add 11,11,0; lwz 3,-4(9); lwz 28,-4(11); bl _s8028ABFC_0; mr 26,3; li 4,64; lwz 3,-23020(13); bl _s8028ABFC_1; mr 30,3; li 0,5; stw 0,0x0(30); lis 8,-32700; stw 29,0x8(30); addi 7,8,-6476; stw 29,0xc(30); mr 3,28; stw 29,0x10(30); mr 4,27; lwz 9,0x4c(31); lwz 11,0x8(9); lwz 10,0x4(11); lwz 9,0x18(10); lwz 0,0x0(9); stw 0,0x4(30); stw 7,0x18(1); lhz 9,-6476(8); addi 9,9,1; sth 9,-6476(8); bl _s8028ABFC_2; lwz 3,0x4c(31); lis 9,-32704; lfs f1,0x4d30(9); mr 6,30; li 9,1; addi 5,26,16384; stw 29,0x14(1); addi 3,3,36; mr 7,27; mr 8,31; stw 29,0x8(1); li 4,0; stw 29,0xc(1); li 10,-1; stw 29,0x10(1); bl _s8028ABFC_3; mr 30,3; li 11,0; lwz 0,0x0(30); rlwinm 9,0,0,25,31; addi 9,9,-12; cmplwi 9,7; bgt 1f; rlwinm 11,0,5,31,31; 1:; cmpwi 11,0; beq 2f; lwz 9,0x4c(30); li 0,1; stw 0,0x2c(9); 2:; cmpwi 30,0; beq 4f; lwz 4,0x18(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 3f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s8028ABFC_4; 3:; mr 3,30; b 6f; 4:; lwz 4,0x18(1); lwz 31,-22936(13); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 5f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s8028ABFC_5; 5:; mr 3,31; 6:; lwz 0,0x3c(1); mtspr 8,0; lmw 26,0x20(1); addi 1,1,56"
extern "C" void _s8028ABFC_0();
extern "C" void _s8028ABFC_1();
extern "C" void _s8028ABFC_2();
extern "C" void _s8028ABFC_3();
extern "C" void _s8028ABFC_4();
extern "C" void _s8028ABFC_5();
extern "C" void f_8028ABFC() {}
