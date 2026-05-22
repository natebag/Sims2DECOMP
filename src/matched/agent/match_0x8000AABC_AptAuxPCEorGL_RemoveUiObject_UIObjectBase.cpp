// 0x8000AABC AptAuxPCEorGL_RemoveUiObject(UIObjectBase (140 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32697; li 8,0; addi 9,9,-768; mr 10,8; lwzx 0,9,8; b 1f; 0:; addi 10,10,1; cmpwi 10,9; bgt 2f; lis 9,-32697; rlwinm 11,10,2,0,29; addi 9,9,-768; lwzx 0,9,11; 1:; cmpw 3,0; bne 0b; li 8,1; 2:; cmpwi 8,0; beq 5f; cmpwi 10,8; bgt 4f; lis 9,-32697; rlwinm 0,10,2,0,29; addi 9,9,-768; add 9,0,9; 3:; lwz 0,0x4(9); addi 10,10,1; cmpwi 10,8; stw 0,0x0(9); addi 9,9,4; ble 3b; 4:; lis 9,-32697; li 0,0; stw 0,-732(9); 5:; mr 3,8"
extern "C" void f_8000AABC() {}
