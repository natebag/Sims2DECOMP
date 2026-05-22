// 0x80197B4C CASGeneticsTarget::SetVariableSubnav(int, (312 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stw 31,0x14(1); stw 0,0x1c(1); mr 31,3; cmpwi 7,4,4; beq cr7,0f; ble cr7,6f; cmpwi 4,5; beq 6f; cmpwi 4,6; bne 6f; 0:; lwz 0,0x300(31); andi. 9,0,16; beq 5f; lwz 9,0x2f4(31); mfcr 0; rlwinm 0,0,31,31,31; stw 0,0x2f4(31); bne cr7,1f; cmpwi 9,0; beq 2f; 1:; cmpwi 4,6; bne 6f; cmpwi 9,1; bne 6f; 2:; lwz 0,-31440(13); li 9,1; cmpwi 0,0; bne 3f; li 9,0; 3:; cmpwi 9,0; bne 6f; lis 9,-32705; lis 3,-32705; addi 9,9,-15588; addi 3,3,-14976; stw 9,0x8(1); li 4,0; li 5,0; li 6,1; addi 7,1,8; bl _s80197B4C_0; lis 9,-32697; lwz 8,0x5bc0(9); lwz 10,0x134c(8); mr 9,10; cmpwi 10,0; bge 4f; addi 9,10,3; 4:; rlwinm 9,9,0,0,29; lwz 11,0x1348(8); subf 9,9,10; li 0,-2; .long 0x5C00483E; and 11,11,0; stw 11,0x1348(8); lwz 3,0x84(31); bl _s80197B4C_1; lwz 4,0x2f4(31); mr 5,3; mr 3,31; xori 4,4,1; subfic 0,4,0; adde 4,0,4; bl _s80197B4C_2; li 0,4; stw 0,-31440(13); bl _s80197B4C_3; b 6f; 5:; mfcr 0; rlwinm 0,0,31,31,31; stw 0,0x2f4(31); 6:; lwz 0,0x1c(1); mtspr 8,0; lwz 31,0x14(1); addi 1,1,24"
extern "C" void _s80197B4C_0();
extern "C" void _s80197B4C_1();
extern "C" void _s80197B4C_2();
extern "C" void _s80197B4C_3();
extern "C" void f_80197B4C() {}
