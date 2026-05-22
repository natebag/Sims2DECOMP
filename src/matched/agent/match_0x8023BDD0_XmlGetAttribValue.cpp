// 0x8023BDD0 XmlGetAttribValue (308 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 30,5; mr 29,6; bl _s8023BDD0_0; mr. 3,3; beq 2f; lbz 0,0x0(3); li 31,0; cmpwi 0,0; beq 1f; cmpwi 0,61; beq 3f; 0:; addi 31,31,1; lbzx 0,3,31; cmpwi 0,0; beq 1f; cmpwi 0,61; bne 0b; 1:; lbzx 0,3,31; cmpwi 0,61; beq 3f; 2:; li 3,-1; b 14f; 3:; addi 31,31,1; addi 28,29,-1; b 5f; 4:; addi 31,31,1; 5:; lbzx 0,3,31; cmpwi 0,32; beq 4b; cmpwi 0,9; beq 4b; lbzx 0,3,31; cmpwi 0,34; beq 6f; cmpwi 0,39; bne 7f; 6:; mr 29,0; addi 31,31,1; b 8f; 7:; li 29,0; 8:; add 3,3,31; lbz 9,0x0(3); li 31,0; b 12f; 9:; cmpwi 9,38; bne 10f; mr 4,30; addi 3,3,1; addi 30,30,1; bl _s8023BDD0_1; b 11f; 10:; stb 9,0x0(30); addi 3,3,1; addi 30,30,1; 11:; lbz 9,0x0(3); addi 31,31,1; 12:; rlwinm 0,9,0,24,31; cmpwi 0,0; beq 13f; cmpw 0,29; beq 13f; cmpwi 0,62; beq 13f; cmpw 31,28; blt 9b; 13:; li 0,0; addi 3,31,1; stb 0,0x0(30); 14:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s8023BDD0_0();
extern "C" void _s8023BDD0_1();
extern "C" void f_8023BDD0() {}
