// 0x8023BB68 XmlNext (224 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lbz 0,0x0(31); b 1f; 0:; lbzu 0,0x1(31); 1:; cmpwi 0,0; beq 2f; cmpwi 0,60; bne 0b; 2:; mr 3,31; b 11f; 3:; lbz 0,0x0(3); b 5f; 4:; lbzu 0,0x1(3); 5:; cmpwi 0,0; beq 6f; cmpwi 0,60; bne 4b; 6:; li 11,0; b 8f; 7:; addi 11,11,1; 8:; lbzx 0,3,11; rlwinm 9,0,0,24,31; mr 10,0; cmplwi 9,32; ble 10f; cmpwi 9,62; beq 9f; lbzx 0,31,11; cmplwi 0,32; ble 9f; cmpwi 0,62; beq 9f; cmpw 9,0; beq 7b; 9:; rlwinm 0,10,0,24,31; cmplwi 0,32; ble 10f; cmpwi 0,62; bne 11f; 10:; lbzx 0,31,11; cmplwi 0,32; ble 12f; cmpwi 0,62; beq 12f; 11:; bl _s8023BB68_0; mr. 3,3; bne 3b; 12:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s8023BB68_0();
extern "C" void f_8023BB68() {}
