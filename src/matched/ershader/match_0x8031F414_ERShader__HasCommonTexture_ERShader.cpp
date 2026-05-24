// 0x8031F414 ERShader::HasCommonTexture(ERShader (300 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr. 4,4; beq 0f; cmpwi 5,0; bne 1f; 0:; li 3,0; blr; 1:; lwz 0,0x58(5); andi. 9,0,2; li 0,0; bne 4f; lwz 0,0x14(5); cmpwi 0,0; beq 2f; mr 9,0; b 3f; 2:; lwz 11,0x18(5); li 9,0; cmpwi 11,0; beq 3f; lwz 9,0x14(11); 3:; lwz 0,0x4(9); rlwinm 0,0,6,31,31; 4:; cmpwi 0,0; bne 0b; lwz 0,0x14(4); mr 8,0; cmpwi 0,0; beq 5f; mr 10,8; b 6f; 5:; lwz 9,0x18(4); li 10,0; cmpwi 9,0; beq 6f; lwz 10,0x14(9); 6:; lwz 0,0x14(5); cmpwi 0,0; beq 7f; mr 11,0; b 8f; 7:; lwz 9,0x18(5); li 11,0; cmpwi 9,0; beq 8f; lwz 11,0x14(9); 8:; lbz 9,0x0(10); lbz 0,0x0(11); cmpw 9,0; bne 0b; cmpwi 8,0; beq 9f; mr 9,8; b 10f; 9:; lwz 11,0x18(4); li 9,0; cmpwi 11,0; beq 10f; lwz 9,0x14(11); 10:; lbz 10,0x0(9); li 11,0; cmpw 11,10; bge 12f; addi 5,5,40; addi 4,4,40; 11:; lwz 9,0x0(4); lwz 0,0x0(5); addi 4,4,4; addi 5,5,4; cmpw 9,0; bne 0b; addi 11,11,1; cmpw 11,10; blt 11b; 12:; li 3,1"

struct ERShader {
    void HasCommonTexture_ERShader();
};

void ERShader::HasCommonTexture_ERShader() {
}
