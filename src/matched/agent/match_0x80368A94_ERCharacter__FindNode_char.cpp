// 0x80368A94 ERCharacter::FindNode(char (132 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 29,3; li 31,0; addi 9,29,20; mr 27,4; lwz 0,0x4(9); cmpw 31,0; bge 2f; mr 28,9; li 30,0; 0:; lwz 3,0x14(29); mr 4,27; add 3,3,30; addi 3,3,180; bl _s80368A94_0; cmpwi 3,0; bne 1f; mr 3,31; b 3f; 1:; lwz 0,0x4(28); addi 31,31,1; addi 30,30,184; cmpw 31,0; blt 0b; 2:; li 3,-1; 3:; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s80368A94_0();
extern "C" void f_80368A94() {}
