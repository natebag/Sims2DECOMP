// 0x8023C40C XmlAttribGetString (308 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 28,6; mr 30,7; mr. 31,5; beq 0f; cmpwi 28,0; bgt 1f; 0:; li 3,-1; b 17f; 1:; bl _s8023C40C_0; mr. 3,3; beq 11f; lbz 9,0x0(3); b 3f; 2:; lbzu 9,0x1(3); 3:; addi 9,9,-1; cmplwi 9,31; ble 2b; lbz 0,0x0(3); cmpwi 0,34; beq 4f; cmpwi 0,39; bne 5f; 4:; mr 30,0; addi 3,3,1; b 6f; 5:; li 30,0; 6:; li 29,1; b 10f; 7:; cmpwi 9,38; bne 8f; mr 4,31; addi 3,3,1; addi 31,31,1; bl _s8023C40C_1; b 9f; 8:; stb 9,0x0(31); addi 3,3,1; addi 31,31,1; 9:; addi 29,29,1; 10:; cmpw 29,28; bge 14f; lbz 9,0x0(3); rlwinm 0,9,0,24,31; cmpw 0,30; beq 14f; cmpwi 0,0; beq 14f; cmpwi 0,62; bne 7b; b 14f; 11:; cmpwi 30,0; beq 15f; li 29,1; b 13f; 12:; stb 0,0x0(31); addi 29,29,1; addi 30,30,1; addi 31,31,1; 13:; cmpw 29,28; bge 14f; lbz 0,0x0(30); cmpwi 0,0; bne 12b; 14:; li 0,0; stb 0,0x0(31); b 16f; 15:; li 29,0; 16:; addi 3,29,-1; 17:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s8023C40C_0();
extern "C" void _s8023C40C_1();
extern "C" void f_8023C40C() {}
