// 0x802DEB8C local_atoi(char (160 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 31,3; mr 29,4; li 30,0; li 28,1; b 1f; 0:; addi 31,31,1; 1:; lbz 3,0x0(31); extsb 3,3; bl _s802DEB8C_0; cmpwi 3,0; bne 0b; lbz 0,0x0(31); cmpwi 0,45; bne 2f; li 28,-1; addi 31,31,1; 2:; lbz 0,0x0(31); cmpwi 7,29,0; b 4f; 3:; mulli 9,30,10; lbzu 0,0x1(31); addi 9,9,-48; add 30,9,11; 4:; extsb 11,0; cmpwi 11,47; ble 5f; cmpwi 11,57; ble 3b; 5:; beq cr7,6f; stw 31,0x0(29); 6:; mullw 3,30,28; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s802DEB8C_0();
extern "C" void f_802DEB8C() {}
