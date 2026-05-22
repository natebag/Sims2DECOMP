// 0x80289974 AptCharacterInst::sMethod_duplicateMovieClip(AptValue (156 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); lis 9,-32694; mr 29,3; lwz 10,-16032(9); cmpwi 4,2; addi 9,9,-16032; lwz 0,0x8(9); rlwinm 11,10,2,0,29; addi 9,10,-1; rlwinm 9,9,2,0,29; add 11,11,0; add 9,9,0; lwz 30,-4(11); lwz 3,-4(9); ble 0f; addi 9,10,-2; rlwinm 9,9,2,0,29; add 9,9,0; lwz 31,-4(9); b 1f; 0:; li 31,0; 1:; bl _s80289974_0; addi 8,3,16384; mr 4,29; lis 3,-32694; mr 7,30; addi 3,3,-16032; mr 9,31; li 5,0; mr 6,4; bl _s80289974_1; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s80289974_0();
extern "C" void _s80289974_1();
extern "C" void f_80289974() {}
