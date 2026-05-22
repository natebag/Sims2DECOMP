// 0x801A0258 CASRoommateTarget::SetVariableSubnav(int, (192 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x8c(3); cmpwi 0,0; beqlr; cmpwi 5,0; beqlr; lwz 9,0x84(3); lwz 0,0x18(9); cmpwi 0,0; beqlr; lwz 11,0x90(3); li 10,0; b 2f; 0:; lis 9,-32697; mr 0,11; lwz 9,0x5bc0(9); cmpwi 11,0; bge 1f; addi 0,11,3; 1:; lwz 9,0x1348(9); rlwinm 0,0,0,0,29; subf 0,0,11; srw 9,9,0; andi. 0,9,1; bne 4f; 2:; add 9,11,5; mr 0,9; cmpwi 9,0; bge 3f; addi 0,9,3; 3:; rlwinm 0,0,0,0,29; addi 10,10,1; subf 11,0,9; cmpwi 10,3; ble 0b; 4:; lis 9,-32697; mr 0,11; lwz 9,0x5bc0(9); cmpwi 11,0; bge 5f; addi 0,11,3; 5:; lwz 9,0x1348(9); rlwinm 0,0,0,0,29; subf 0,0,11; srw 9,9,0; andi. 0,9,1; beqlr; stw 11,0x90(3)"
extern "C" void f_801A0258() {}
