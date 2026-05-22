// 0x8023C6AC XmlAttribGetToken (184 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,5; lis 31,8224; bl _s8023C6AC_0; ori 31,31,8224; li 29,0; mr. 3,3; bne 0f; mr 3,30; b 8f; 0:; lbz 9,0x0(3); b 2f; 1:; lbzu 9,0x1(3); 2:; addi 9,9,-1; cmplwi 9,31; ble 1b; lbz 0,0x0(3); cmpwi 0,34; beq 3f; cmpwi 0,39; bne 4f; 3:; mr 29,0; addi 3,3,1; 4:; lbz 9,0x0(3); b 6f; 5:; rlwinm 0,31,8,0,23; or 31,9,0; lbzu 9,0x1(3); 6:; rlwinm 0,9,0,24,31; cmplwi 0,32; ble 7f; cmpw 0,29; beq 7f; cmpwi 0,62; beq 7f; cmpwi 0,0; bne 5b; 7:; mr 3,31; 8:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8023C6AC_0();
extern "C" void f_8023C6AC() {}
