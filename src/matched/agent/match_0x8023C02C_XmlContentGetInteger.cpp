// 0x8023C02C XmlContentGetInteger (180 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,4; li 30,1; bl _s8023C02C_0; mr. 3,3; bne 0f; mr 3,31; b 7f; 0:; lbz 9,0x0(3); b 2f; 1:; lbzu 9,0x1(3); 2:; addi 9,9,-1; cmplwi 9,31; ble 1b; lbz 0,0x0(3); cmpwi 0,43; bne 3f; li 30,1; addi 3,3,1; 3:; lbz 0,0x0(3); cmpwi 0,45; bne 4f; li 30,-1; addi 3,3,1; 4:; lbz 10,0x0(3); li 11,0; addi 0,10,-48; cmplwi 0,9; bgt 6f; 5:; rlwinm 9,10,0,28,31; mulli 11,11,10; lbzu 10,0x1(3); addi 0,10,-48; add 11,11,9; cmplwi 0,9; ble 5b; 6:; mullw 3,30,11; 7:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8023C02C_0();
extern "C" void f_8023C02C() {}
