// 0x802435E4 memset (148 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr 9,3; cmplwi 5,3; ble 3f; andi. 0,3,3; bne 3f; rlwinm 4,4,0,24,31; mr 11,3; rlwinm 0,4,8,0,23; or 0,0,4; rlwinm 9,0,16,0,15; or 0,0,9; cmplwi 5,15; ble 2f; 0:; stw 0,0x0(11); addi 5,5,-16; stwu 0,0x4(11); cmplwi 5,15; stwu 0,0x4(11); stwu 0,0x4(11); addi 11,11,4; bgt 0b; b 2f; 1:; stw 0,0x0(11); addi 5,5,-4; addi 11,11,4; 2:; cmplwi 5,3; bgt 1b; mr 9,11; 3:; cmpwi 5,0; addi 5,5,-1; beqlr; 4:; stb 4,0x0(9); cmpwi 5,0; addi 9,9,1; addi 5,5,-1; bne 4b"
extern "C" void f_802435E4() {}
