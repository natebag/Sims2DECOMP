// 0x800A53E0 FileList::Find(ResFile (144 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); stw 4,0x18(1); addi 9,1,24; lwz 10,0x4(3); lwz 11,0x4(10); 0:; cmpwi 11,0; beq 2f; lwz 0,0x10(11); cmplw 0,4; blt 1f; mr 10,11; lwz 11,0x8(10); b 0b; 1:; lwz 11,0xc(11); b 0b; 2:; lwz 11,0x4(3); cmpw 10,11; beq 3f; lwz 9,0x0(9); lwz 0,0x10(10); cmplw 9,0; bge 4f; 3:; mr 10,11; 4:; lwz 0,0x4(3); li 9,1; stw 10,0x8(1); cmpw 10,0; stw 0,0x10(1); bne 5f; li 9,0; 5:; cmpwi 9,0; li 3,0; beq 6f; lwz 3,0x18(10); 6:; addi 1,1,32"
extern "C" void f_800A53E0() {}
