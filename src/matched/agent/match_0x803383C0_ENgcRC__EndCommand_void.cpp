// 0x803383C0 ENgcRC::EndCommand(void) (104 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); mr 10,3; li 0,1; lbz 9,0x18(10); lwz 11,0xc(10); addi 9,9,-1; stw 0,0x14(10); stb 9,0x18(10); cmpwi 11,0; bne 0f; lwz 9,0x0(10); lwz 0,0x4c(9); cmpwi 0,0; bne 0f; lwz 9,0x70(10); lha 3,0x10(9); lwz 0,0x14(9); add 3,10,3; mtspr 8,0; blrl; 0:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void f_803383C0() {}
