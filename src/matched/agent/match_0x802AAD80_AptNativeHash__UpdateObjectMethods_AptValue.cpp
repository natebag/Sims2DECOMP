// 0x802AAD80 AptNativeHash::UpdateObjectMethods(AptValue (176 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lwz 4,0x0(4); mr 31,3; mr 30,6; li 0,0; rlwinm 9,4,0,25,31; addi 9,9,-12; cmplwi 9,7; bgt 0f; rlwinm 0,4,5,31,31; 0:; cmpwi 0,0; bne 3f; lwz 3,0x0(5); lhz 4,0x2(3); addi 3,3,8; bl _s802AAD80_0; mr. 3,3; beq 3f; lwz 3,0x4(3); cmpwi 3,199; ble 3f; addi 0,3,-200; lis 9,-32703; addi 9,9,-14892; rlwinm 0,0,2,0,29; lwzx 3,9,0; cmpwi 3,-1; beq 3f; cmpwi 30,0; beq 1f; lwz 0,0x10(31); andc 0,0,3; b 2f; 1:; lwz 0,0x10(31); or 0,0,3; 2:; stw 0,0x10(31); 3:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s802AAD80_0();
extern "C" void f_802AAD80() {}
