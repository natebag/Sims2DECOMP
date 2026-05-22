// 0x80138C20 SpacePartition::SpacePartition(void) (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mr 9,3; li 0,0; stw 0,0xc(9); addi 11,9,20; stw 0,0x10(9); addi 10,9,28; stw 0,0x4(11); addi 8,9,36; stw 0,0x1c(9); addi 11,9,44; stw 0,0x4(10); addi 7,9,52; stw 0,0x4(8); addi 6,9,60; stw 0,0x2c(9); addi 10,9,68; stw 0,0x4(11); addi 8,9,76; stw 0,0x4(7); addi 11,9,84; stw 0,0x3c(9); stw 0,0x4(6); stw 0,0x4(10); stw 0,0x4c(9); stw 0,0x4(8); stw 0,0x4(11); addi 1,1,48"
extern "C" void f_80138C20() {}
