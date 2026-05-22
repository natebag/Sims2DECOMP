// 0x80169B38 CasSimDescriptionS2C::InnerLayerHalfTorsoRequired(CasSimPartsS2C (124 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 30,0x18(1); stw 0,0x24(1); mr 31,3; mr 30,4; addi 3,1,8; li 5,12; mr 4,31; bl _s80169B38_0; lbz 5,0xb4(31); mr 3,30; li 4,12; addi 6,1,8; extsb 5,5; bl _s80169B38_1; cmpwi 3,0; bne 0f; li 3,0; b 1f; 0:; lbz 4,0xb4(31); mr 3,30; extsb 4,4; bl _s80169B38_2; subfic 0,3,0; adde 3,0,3; 1:; lwz 0,0x24(1); mtspr 8,0; lmw 30,0x18(1); addi 1,1,32"
extern "C" void _s80169B38_0();
extern "C" void _s80169B38_1();
extern "C" void _s80169B38_2();
extern "C" void f_80169B38() {}
