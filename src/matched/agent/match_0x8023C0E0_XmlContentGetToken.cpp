// 0x8023C0E0 XmlContentGetToken (136 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,4; lis 31,8224; bl _s8023C0E0_0; ori 31,31,8224; mr. 3,3; bne 0f; mr 3,30; b 6f; 0:; lbz 9,0x0(3); b 2f; 1:; lbzu 9,0x1(3); 2:; addi 9,9,-1; cmplwi 9,31; ble 1b; lbz 9,0x0(3); b 4f; 3:; rlwinm 0,31,8,0,23; or 31,9,0; lbzu 9,0x1(3); 4:; rlwinm 0,9,0,24,31; cmplwi 0,32; ble 5f; cmpwi 0,60; bne 3b; 5:; mr 3,31; 6:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8023C0E0_0();
extern "C" void f_8023C0E0() {}
