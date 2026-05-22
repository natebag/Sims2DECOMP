// 0x800A5688 FileList::ReleaseRef(iResFile (276 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stw 31,0x34(1); stw 0,0x3c(1); lwz 0,0x8(4); mr 31,3; lwz 11,0x4(31); addi 9,1,40; stw 0,0x28(1); lwz 10,0x4(11); cmpwi 10,0; beq 3f; mr 8,0; 0:; lwz 0,0x10(10); cmplw 0,8; blt 1f; mr 11,10; lwz 10,0x8(11); b 2f; 1:; lwz 10,0xc(10); 2:; cmpwi 10,0; bne 0b; 3:; lwz 10,0x4(31); cmpw 11,10; beq 4f; lwz 9,0x0(9); lwz 0,0x10(11); cmplw 9,0; bge 5f; 4:; mr 11,10; 5:; lwz 0,0x4(31); li 9,1; stw 11,0x8(1); cmpw 11,0; stw 0,0x10(1); bne 6f; li 9,0; 6:; cmpwi 9,0; beq 8f; addi 11,11,16; lwz 9,0x4(11); addi 9,9,-1; stw 9,0x4(11); cmpwi 9,0; bne 8f; lwz 5,0x4(31); lwz 0,0x8(1); addi 6,5,12; addi 4,5,4; mr 3,0; stw 0,0x18(1); stw 0,0x20(1); addi 5,5,8; bl _s800A5688_0; mr. 3,3; beq 7f; li 4,28; bl _s800A5688_1; 7:; lwz 9,0x8(31); li 3,1; addi 9,9,-1; stw 9,0x8(31); b 9f; 8:; li 3,0; 9:; lwz 0,0x3c(1); mtspr 8,0; lwz 31,0x34(1); addi 1,1,56"
extern "C" void _s800A5688_0();
extern "C" void _s800A5688_1();
extern "C" void f_800A5688() {}
