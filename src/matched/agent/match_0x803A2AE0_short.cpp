// 0x803A2AE0 short (176 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="subf 0,3,4; srawi. 11,0,3; ble 1f; lha 9,0x0(5); 0:; lha 0,0x0(3); cmpw 0,9; beqlr; lhau 0,0x2(3); cmpw 0,9; beqlr; lhau 0,0x2(3); cmpw 0,9; beqlr; lhau 0,0x2(3); cmpw 0,9; beqlr; addi 3,3,2; addic. 11,11,-1; bgt 0b; 1:; subf 0,3,4; srawi 0,0,1; cmpwi 0,1; beq 3f; ble 4f; cmpwi 0,2; beq 2f; cmpwi 0,3; bne 4f; lha 9,0x0(3); lha 0,0x0(5); cmpw 9,0; beqlr; addi 3,3,2; 2:; lha 9,0x0(3); lha 0,0x0(5); cmpw 9,0; beqlr; addi 3,3,2; 3:; lha 9,0x0(5); lha 0,0x0(3); cmpw 0,9; beqlr; 4:; mr 3,4"
extern "C" int f_803A2AE0() {}
