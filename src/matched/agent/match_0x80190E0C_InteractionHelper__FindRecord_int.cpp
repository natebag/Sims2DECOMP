// 0x80190E0C InteractionHelper::FindRecord(int) (148 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr 10,3; li 11,0; lwz 3,0x4(10); li 9,0; lwz 0,0x4(3); cmpwi 0,0; beq 3f; lwz 3,0x0(10); cmpwi 3,0; beq 7f; 0:; cmpw 9,4; bne 1f; mr 11,3; 1:; lwz 3,0x4(3); addi 9,9,1; cmpwi 3,0; beq 7f; cmpwi 11,0; beq 0b; b 7f; 2:; lwz 3,0x0(3); 3:; lwz 0,0x8(3); cmpwi 0,0; bne 2b; lwz 3,0xc(3); b 6f; 4:; cmpw 9,4; bne 5f; mr 11,3; 5:; lwz 3,0xc(3); addi 9,9,1; 6:; cmpwi 3,0; beq 7f; cmpwi 11,0; beq 4b; 7:; mr 3,11"
extern "C" int f_80190E0C() {}
