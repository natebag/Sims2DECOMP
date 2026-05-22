// 0x800BD6A4 IFFResMap::GetNode(Memory::HandleNode (120 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr 10,3; lwz 9,0x0(10); lwz 0,0x4(10); cmpw 9,0; beq 5f; 0:; lwz 3,0x0(9); lwz 0,0x4(9); cmpw 3,0; beq 4f; mr 11,0; cmpwi 7,6,0; 1:; lwz 0,0xc(3); cmpw 0,4; bne 3f; beq cr7,2f; stw 6,0x14(9); 2:; lwz 0,0x10(9); stw 0,0x0(5); blr; 3:; addi 3,3,88; cmpw 3,11; bne 1b; 4:; lwz 0,0x4(10); addi 9,9,24; cmpw 9,0; bne 0b; 5:; li 0,0; li 3,0; stw 0,0x0(5)"
extern "C" void f_800BD6A4() {}
