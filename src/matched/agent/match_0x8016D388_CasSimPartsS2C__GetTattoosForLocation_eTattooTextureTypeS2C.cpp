// 0x8016D388 CasSimPartsS2C::GetTattoosForLocation(eTattooTextureTypeS2C, (148 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; mr 29,5; lwz 9,0x4(31); li 30,0; lwz 9,0x4(9); cmpwi 9,0; beq 0f; lwz 30,-4(9); 0:; mr 3,31; bl _s8016D388_0; mr 7,3; li 8,0; li 3,0; cmplw 3,30; bge 3f; 1:; lwz 11,0x4(31); mulli 10,8,20; lwz 9,0x4(11); add 9,9,10; lwz 0,0x8(9); cmpw 0,7; bne 2f; stbx 8,29,3; addi 3,3,1; 2:; addi 0,8,1; rlwinm 8,0,0,24,31; cmplw 8,30; blt 1b; 3:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8016D388_0();
extern "C" void f_8016D388() {}
