// 0x803C9260 TArray<EAnimNodeDataPos, (164 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); addi 10,5,-1; cmpwi 5,0; beq 2f; 0:; mr 11,4; addi 5,10,-1; lwz 7,0x0(3); addi 4,11,36; mr 9,3; li 10,24; addi 8,3,36; 1:; lwz 0,0x0(11); addic. 10,10,-24; stw 0,0x0(9); lwz 0,0x4(11); stw 0,0x4(9); lwz 0,0x8(11); stw 0,0x8(9); lwz 0,0xc(11); stw 0,0xc(9); lwz 0,0x10(11); stw 0,0x10(9); lwz 0,0x14(11); addi 11,11,24; stw 0,0x14(9); addi 9,9,24; bne 1b; lwz 0,0x0(11); mr 10,5; cmpwi 10,-1; stw 0,0x0(9); lwz 0,0x4(11); stw 0,0x4(9); lwz 0,0x8(11); stw 0,0x8(9); stw 7,0x0(3); mr 3,8; bne 0b; stw 7,0x8(1); 2:; addi 1,1,16"
extern "C" void f_803C9260() {}
