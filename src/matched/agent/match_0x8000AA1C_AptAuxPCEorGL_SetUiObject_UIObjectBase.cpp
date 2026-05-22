// 0x8000AA1C AptAuxPCEorGL_SetUiObject(UIObjectBase (160 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr. 31,3; li 3,0; beq 3f; mr 3,31; bl _s8000AA1C_0; lis 9,-32697; li 10,0; lwz 0,-768(9); cmpwi 0,0; bne 0f; stw 31,-768(9); b 1f; 0:; addi 10,10,1; cmpwi 10,9; bgt 1f; lis 9,-32697; rlwinm 11,10,2,0,29; addi 9,9,-768; lwzx 0,9,11; cmpwi 0,0; bne 0b; stwx 31,9,11; 1:; cmpwi 10,0; bne 2f; li 3,0; b 3f; 2:; addi 0,10,-1; lis 9,-32697; addi 9,9,-768; rlwinm 0,0,2,0,29; lwzx 3,9,0; 3:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s8000AA1C_0();
extern "C" void f_8000AA1C() {}
