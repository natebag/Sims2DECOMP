// 0x80351864 ENgcTextureUtil::SwizzleToRGB5A3(unsigned (172 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr. 4,4; bge 0f; addi 4,4,3; 0:; srawi 4,4,2; mr. 9,5; bge 1f; addi 9,9,3; 1:; srawi 5,9,2; rlwinm 8,4,3,0,28; li 9,0; cmpw 9,5; bgelr; mulli 12,4,24; 2:; addi 7,9,1; cmpwi 4,0; ble 4f; mtspr 9,4; 3:; lwz 10,0x0(3); add 9,3,8; lwz 0,0x4(3); addi 11,6,8; stw 10,0x0(6); stw 0,0x4(6); lwzx 10,3,8; lwz 0,0x4(9); addi 3,3,8; stw 10,0x8(6); stw 0,0x4(11); addi 6,6,32; .long 0x7C09406E; lwz 10,0x4(9); stwu 0,0x8(11); stw 10,0x4(11); .long 0x7C09406E; lwz 10,0x4(9); stwu 0,0x8(11); stw 10,0x4(11); bdnz 3b; 4:; mr 9,7; add 3,3,12; cmpw 9,5; blt 2b"
extern "C" void f_80351864() {}
