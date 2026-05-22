// 0x80142798 GetObjectAnimRefPassiveInfluence(cXObject (148 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lwz 9,0x4(3); mr 31,5; mr 30,4; lha 0,0x368(9); lwz 9,0x36c(9); add 3,3,0; mtspr 8,9; blrl; bl _s80142798_0; li 0,0; mr. 11,3; stw 0,0x0(31); beq 0f; lwz 9,0x0(11); mr 4,30; lha 3,0x20(9); lwz 0,0x24(9); add 3,11,3; mtspr 8,0; blrl; stw 3,0x0(31); 0:; lwz 0,0x0(31); li 3,-1; li 4,-1; cmpwi 0,0; beq 1f; li 3,0; li 4,1; 1:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80142798_0();
extern "C" void f_80142798() {}
