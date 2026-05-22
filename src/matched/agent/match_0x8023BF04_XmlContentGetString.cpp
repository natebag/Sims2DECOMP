// 0x8023BF04 XmlContentGetString (296 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 28,5; mr 30,6; mr. 31,4; beq 0f; cmpwi 28,0; bgt 1f; 0:; li 3,-1; b 16f; 1:; bl _s8023BF04_0; mr. 3,3; beq 10f; lbz 9,0x0(3); b 3f; 2:; lbzu 9,0x1(3); 3:; addi 9,9,-1; cmplwi 9,31; ble 2b; li 29,1; b 7f; 4:; cmpwi 9,38; bne 5f; mr 4,31; addi 3,3,1; addi 31,31,1; bl _s8023BF04_1; b 6f; 5:; stb 9,0x0(31); addi 3,3,1; addi 31,31,1; 6:; addi 29,29,1; 7:; cmpw 29,28; bge 9f; lbz 9,0x0(3); rlwinm 0,9,0,24,31; cmpwi 0,0; beq 9f; cmpwi 0,60; bne 4b; b 9f; 8:; addi 29,29,-1; addi 31,31,-1; 9:; cmpwi 29,1; ble 13f; lbz 0,-1(31); cmplwi 0,32; ble 8b; b 13f; 10:; cmpwi 30,0; beq 14f; li 29,1; b 12f; 11:; stb 0,0x0(31); addi 29,29,1; addi 30,30,1; addi 31,31,1; 12:; cmpw 29,28; bge 13f; lbz 0,0x0(30); cmpwi 0,0; bne 11b; 13:; li 0,0; stb 0,0x0(31); b 15f; 14:; li 29,0; 15:; addi 3,29,-1; 16:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s8023BF04_0();
extern "C" void _s8023BF04_1();
extern "C" void f_8023BF04() {}
