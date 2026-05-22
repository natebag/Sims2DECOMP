// 0x801133E8 PassiveInfluenceMap::PassiveInfluenceMap(int, (136 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); mullw 30,4,5; mr 31,3; stw 4,0x0(31); stw 5,0x4(31); rlwinm 3,30,4,0,27; ori 3,3,8; bl _s801133E8_0; addi 3,3,8; addi 10,30,-1; stw 30,-8(3); mr 11,3; cmpwi 30,0; beq 1f; li 0,0; 0:; stw 0,0x0(11); addi 9,11,8; stw 0,0x4(11); cmpwi 10,0; stw 0,0x4(9); addi 11,11,16; addi 10,10,-1; bne 0b; 1:; stw 3,0x8(31); mr 3,31; stw 31,-31784(13); lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"
extern "C" void _s801133E8_0();
extern "C" void f_801133E8() {}
