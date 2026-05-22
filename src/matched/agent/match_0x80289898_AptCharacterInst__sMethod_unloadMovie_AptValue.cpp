// 0x80289898 AptCharacterInst::sMethod_unloadMovie(AptValue (220 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 30,0x20(1); stw 0,0x2c(1); lis 11,-32700; addi 4,1,8; lhz 9,-6476(11); addi 0,11,-6476; stw 0,0x8(1); addi 9,9,1; sth 9,-6476(11); bl _s80289898_0; lwz 11,0x8(1); lis 4,-32704; lwz 30,-22996(13); addi 3,1,24; stw 11,0x10(1); addi 4,4,18440; lhz 9,0x0(11); addi 9,9,1; sth 9,0x0(11); bl _s80289898_1; addi 4,1,24; mr 3,30; addi 5,1,16; bl _s80289898_2; lwz 4,0x18(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 0f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s80289898_3; 0:; lwz 4,0x8(1); lwz 30,-22936(13); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 1f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s80289898_4; 1:; mr 3,30; lwz 0,0x2c(1); mtspr 8,0; lmw 30,0x20(1); addi 1,1,40"
extern "C" void _s80289898_0();
extern "C" void _s80289898_1();
extern "C" void _s80289898_2();
extern "C" void _s80289898_3();
extern "C" void _s80289898_4();
extern "C" void f_80289898() {}
