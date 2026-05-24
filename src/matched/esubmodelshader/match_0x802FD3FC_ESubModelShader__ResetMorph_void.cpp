// 0x802FD3FC ESubModelShader::ResetMorph(void) (136 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 29,3; lwz 0,0x30(29); cmpwi 0,0; beq 3f; ble 3f; mr 30,0; li 31,0; 0:; lwz 11,0x2c(29); lwz 0,0x10(29); add 9,11,31; lwz 5,0x18(9); andi. 9,0,16; beq 1f; lwzx 3,11,31; rlwinm 5,5,3,0,28; li 4,0; bl _s802FD3FC_0; b 2f; 1:; lwzx 3,11,31; rlwinm 5,5,4,0,27; li 4,0; bl _s802FD3FC_1; 2:; addi 31,31,52; addic. 30,30,-1; bne 0b; 3:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"

extern "C" void _s802FD3FC_0();
extern "C" void _s802FD3FC_1();

struct ESubModelShader {
    void ResetMorph();
};

void ESubModelShader::ResetMorph() {
}
