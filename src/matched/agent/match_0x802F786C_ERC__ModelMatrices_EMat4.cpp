// 0x802F786C ERC::ModelMatrices(EMat4 (148 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; mr 31,5; lwz 9,0x70(30); lwz 0,0xdc(9); lha 3,0xd8(9); mtspr 8,0; add 3,30,3; blrl; li 0,4; cmpw 0,31; ble 0f; mr 0,31; 0:; li 11,0; addi 5,31,-1; cmpw 11,0; bge 2f; addi 9,30,36; 1:; stw 11,0x0(9); addi 11,11,1; addi 9,9,4; cmpw 11,0; blt 1b; 2:; lwz 0,0x44(30); cmpw 5,0; ble 3f; stw 5,0x44(30); 3:; li 0,1; stw 0,0x34(30); lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void f_802F786C() {}
