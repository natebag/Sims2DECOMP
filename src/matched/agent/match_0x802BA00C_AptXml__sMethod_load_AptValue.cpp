// 0x802BA00C AptXml::sMethod_load(AptValue (264 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stw 31,0x14(1); stw 0,0x1c(1); mr 31,3; cmpwi 4,0; ble 3f; lwz 0,0x0(31); rlwinm 0,0,0,25,31; cmpwi 0,33; bne 3f; lis 9,-32694; li 10,0; lwz 11,-16032(9); addi 9,9,-16032; lwz 0,0x8(9); rlwinm 11,11,2,0,29; add 11,11,0; lwz 3,-4(11); lwz 9,0x0(3); rlwinm 0,9,0,25,31; cmpwi 0,1; beq 0f; cmpwi 0,42; bne 1f; 0:; andis. 0,9,2048; beq 1f; li 10,1; 1:; cmpwi 10,0; beq 3f; lis 11,-32700; addi 4,1,8; lhz 9,-6476(11); addi 0,11,-6476; stw 0,0x8(1); addi 9,9,1; sth 9,-6476(11); bl _s802BA00C_0; lwz 11,0x24(31); cmpwi 11,0; beq 2f; lwz 9,0x0(11); lwz 4,0x8(1); lha 3,0x108(9); lwz 0,0x10c(9); addi 4,4,8; add 3,11,3; mtspr 8,0; blrl; 2:; lwz 4,0x8(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 3f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s802BA00C_1; 3:; lwz 3,-22936(13); lwz 0,0x1c(1); mtspr 8,0; lwz 31,0x14(1); addi 1,1,24"
extern "C" void _s802BA00C_0();
extern "C" void _s802BA00C_1();
extern "C" void f_802BA00C() {}
