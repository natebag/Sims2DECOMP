// 0x803C1750 EInstance (176 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="subf 0,3,4; srawi. 11,0,4; ble 1f; lwz 9,0x0(5); 0:; lwz 0,0x0(3); cmpw 0,9; beqlr; lwzu 0,0x4(3); cmpw 0,9; beqlr; lwzu 0,0x4(3); cmpw 0,9; beqlr; lwzu 0,0x4(3); cmpw 0,9; beqlr; addi 3,3,4; addic. 11,11,-1; bgt 0b; 1:; subf 0,3,4; srawi 0,0,2; cmpwi 0,1; beq 3f; ble 4f; cmpwi 0,2; beq 2f; cmpwi 0,3; bne 4f; lwz 9,0x0(3); lwz 0,0x0(5); cmpw 9,0; beqlr; addi 3,3,4; 2:; lwz 9,0x0(3); lwz 0,0x0(5); cmpw 9,0; beqlr; addi 3,3,4; 3:; lwz 9,0x0(5); lwz 0,0x0(3); cmpw 0,9; beqlr; 4:; mr 3,4"
extern "C" int f_803C1750() {}
