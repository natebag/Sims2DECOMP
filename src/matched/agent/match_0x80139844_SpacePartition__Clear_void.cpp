// 0x80139844 SpacePartition::Clear(void) (120 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 11,0xc(3); addi 10,3,12; lwz 0,0x4(10); mr 9,11; addi 8,3,76; addi 7,3,28; cmpw 11,0; addi 6,3,44; addi 5,3,60; beq 1f; 0:; addi 9,9,20; cmpw 9,0; bne 0b; 1:; stw 11,0x4(10); lwz 11,0x4c(3); lwz 0,0x4(8); mr 9,11; cmpw 11,0; beq 3f; 2:; addi 9,9,44; cmpw 9,0; bne 2b; 3:; stw 11,0x4(8); lwz 0,0x1c(3); stw 0,0x4(7); lwz 9,0x2c(3); stw 9,0x4(6); lwz 0,0x3c(3); stw 0,0x4(5)"
extern "C" void f_80139844() {}
