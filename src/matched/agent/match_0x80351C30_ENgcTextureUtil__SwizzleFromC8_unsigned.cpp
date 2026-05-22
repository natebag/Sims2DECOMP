// 0x80351C30 ENgcTextureUtil::SwizzleFromC8(unsigned (184 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); stw 31,0xc(1); mr 31,6; mr. 4,4; bge 0f; addi 4,4,7; 0:; srawi 4,4,3; mr. 9,5; bge 1f; addi 9,9,3; 1:; srawi 6,9,2; rlwinm 12,4,3,0,28; li 9,0; cmpw 9,6; bge 6f; 2:; mullw 0,9,4; li 11,0; addi 5,9,1; cmpw 11,4; rlwinm 0,0,5,0,26; add 9,31,0; bge 5f; 3:; li 0,4; addi 8,11,1; mtspr 9,0; addi 7,3,32; mr 11,9; addi 10,9,8; 4:; lwz 0,0x0(3); lwz 9,0x4(3); stw 0,0x0(11); addi 3,3,8; stw 9,0x4(11); add 11,11,12; bdnz 4b; mr 11,8; mr 9,10; mr 3,7; cmpw 11,4; blt 3b; 5:; mr 9,5; cmpw 9,6; blt 2b; 6:; lwz 31,0xc(1); addi 1,1,16"
extern "C" void f_80351C30() {}
