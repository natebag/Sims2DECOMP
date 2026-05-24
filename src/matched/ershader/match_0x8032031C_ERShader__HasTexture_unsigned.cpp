// 0x8032031C ERShader::HasTexture(unsigned (192 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="0:; lwz 0,0x58(3); andi. 9,0,2; beq 1f; lwz 3,0x18(3); b 0b; 1:; andi. 9,0,2; li 0,0; bne 4f; lwz 0,0x14(3); cmpwi 0,0; beq 2f; mr 9,0; b 3f; 2:; lwz 11,0x18(3); li 9,0; cmpwi 11,0; beq 3f; lwz 9,0x14(11); 3:; lwz 0,0x4(9); rlwinm 0,0,6,31,31; 4:; cmpwi 0,0; beq 7f; lwz 0,0x30(3); li 9,0; cmplw 9,0; bge 9f; lwz 3,0x38(3); mr 11,0; 5:; lwz 0,0x0(3); addi 3,3,4; cmpw 0,4; beq 6f; addi 9,9,1; cmplw 9,11; blt 5b; b 9f; 6:; li 3,1; blr; 7:; addi 9,3,44; addi 3,3,40; 8:; lwz 0,0x0(3); addi 3,3,4; cmpw 0,4; beq 6b; cmpw 3,9; ble 8b; 9:; li 3,0"

struct ERShader {
    void HasTexture();
};

void ERShader::HasTexture() {
}
