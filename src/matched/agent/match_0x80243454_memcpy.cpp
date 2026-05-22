// 0x80243454 memcpy (164 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr 9,3; cmplwi 5,15; ble 3f; or 0,4,3; andi. 11,0,3; bne 3f; mr 11,3; 0:; lwz 9,0x0(4); addi 5,5,-16; cmplwi 5,15; stw 9,0x0(11); lwzu 0,0x4(4); stwu 0,0x4(11); lwzu 9,0x4(4); stwu 9,0x4(11); lwzu 0,0x4(4); stwu 0,0x4(11); addi 4,4,4; addi 11,11,4; bgt 0b; cmplwi 5,3; ble 2f; 1:; lwz 0,0x0(4); addi 5,5,-4; addi 4,4,4; cmplwi 5,3; stw 0,0x0(11); addi 11,11,4; bgt 1b; 2:; mr 9,11; 3:; cmpwi 5,0; addi 5,5,-1; beqlr; 4:; lbz 0,0x0(4); cmpwi 5,0; addi 4,4,1; addi 5,5,-1; stb 0,0x0(9); addi 9,9,1; bne 4b"
extern "C" void f_80243454() {}
