// 0x80351910 ENgcTextureUtil::SwizzleToC4(unsigned (148 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr. 4,4; bge 0f; addi 4,4,7; 0:; srawi 4,4,3; mr. 9,5; bge 1f; addi 9,9,7; 1:; srawi 12,9,3; rlwinm 5,4,2,0,29; li 9,0; cmpw 9,12; bgelr; 2:; mullw 0,9,4; li 10,0; addi 7,9,1; cmpw 10,4; rlwinm 0,0,5,0,26; add 11,3,0; bge 5f; 3:; li 0,8; mr 9,11; mtspr 9,0; addi 10,10,1; addi 8,6,32; addi 11,11,4; 4:; lwz 0,0x0(9); add 9,9,5; stw 0,0x0(6); addi 6,6,4; bdnz 4b; mr 6,8; cmpw 10,4; blt 3b; 5:; mr 9,7; cmpw 9,12; blt 2b"
extern "C" void f_80351910() {}
