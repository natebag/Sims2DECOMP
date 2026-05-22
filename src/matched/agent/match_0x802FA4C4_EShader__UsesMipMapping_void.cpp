// 0x802FA4C4 EShader::UsesMipMapping(void) (180 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x4(3); andis. 9,0,1024; beq 3f; addi 3,3,100; lbz 0,0x24(3); cmpwi 0,0; beq 6f; lwz 3,0x4(3); cmpwi 3,0; beq 6f; li 11,0; cmpw 11,0; bge 6f; mr 10,0; 0:; lwz 9,0x0(3); addi 3,3,4; cmpwi 9,0; beq 1f; lwz 0,0x8(9); andi. 9,0,32; bne 2f; 1:; addi 11,11,1; cmpw 11,10; blt 0b; b 6f; 2:; li 3,1; blr; 3:; lbz 0,0x0(3); li 11,0; cmplw 11,0; bge 6f; mr 10,0; addi 3,3,100; 4:; lwz 9,0x0(3); addi 3,3,64; cmpwi 9,0; beq 5f; lwz 0,0x8(9); andi. 9,0,32; bne 2b; 5:; addi 11,11,1; cmplw 11,10; blt 4b; 6:; li 3,0"
extern "C" int f_802FA4C4() {}
