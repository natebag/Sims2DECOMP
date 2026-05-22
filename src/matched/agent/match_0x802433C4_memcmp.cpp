// 0x802433C4 memcmp (144 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr 9,3; cmplwi 5,3; ble 2f; or 0,9,4; andi. 11,0,3; bne 2f; lwz 0,0x0(4); lwz 9,0x0(3); cmpw 9,0; bne 1f; 0:; addi 5,5,-4; addi 3,3,4; addi 4,4,4; cmplwi 5,3; ble 1f; lwz 9,0x0(3); lwz 0,0x0(4); cmpw 9,0; beq 0b; 1:; mr 9,3; 2:; cmpwi 5,0; addi 5,5,-1; beq 5f; 3:; lbz 3,0x0(9); lbz 0,0x0(4); cmpw 3,0; beq 4f; subf 3,0,3; blr; 4:; cmpwi 5,0; addi 9,9,1; addi 4,4,1; addi 5,5,-1; bne 3b; 5:; li 3,0"
extern "C" int f_802433C4() {}
