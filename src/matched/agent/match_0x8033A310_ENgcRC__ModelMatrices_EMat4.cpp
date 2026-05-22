// 0x8033A310 ENgcRC::ModelMatrices(EMat4 (160 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 30,3; mr 29,5; lwz 9,0x70(30); li 28,4; lha 3,0xd8(9); lwz 0,0xdc(9); add 3,30,3; mtspr 8,0; blrl; cmpw 28,29; ble 0f; mr 28,29; 0:; li 31,0; addi 29,29,-1; cmpw 31,28; bge 2f; 1:; lwz 9,0x70(30); mr 4,31; mr 5,31; lha 3,0xe0(9); addi 31,31,1; lwz 0,0xe4(9); add 3,30,3; mtspr 8,0; blrl; cmpw 31,28; blt 1b; 2:; lwz 0,0x44(30); cmpw 29,0; ble 3f; stw 29,0x44(30); 3:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void f_8033A310() {}
