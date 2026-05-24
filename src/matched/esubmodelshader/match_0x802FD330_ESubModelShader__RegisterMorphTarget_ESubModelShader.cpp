// 0x802FD330 ESubModelShader::RegisterMorphTarget(ESubModelShader (184 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; mr 30,4; lwz 9,0x18(31); mr 29,5; lwz 0,0x18(30); cmpw 9,0; beq 1f; 0:; li 3,0; b 5f; 1:; li 8,0; cmpw 8,9; bge 3f; mr 7,9; lwz 11,0x14(31); lwz 9,0x14(30); addi 11,11,24; addi 10,9,24; 2:; lwz 9,0x0(11); lwz 0,0x0(10); addi 11,11,52; addi 10,10,52; cmpw 9,0; bne 0b; addi 8,8,1; cmpw 8,7; blt 2b; 3:; lwz 0,0x30(31); cmpwi 0,0; bne 4f; mr 3,31; bl _s802FD330_0; mr 3,31; bl _s802FD330_1; 4:; rlwinm 0,29,2,0,29; addi 9,31,56; stwx 30,9,0; li 3,1; 5:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"

extern "C" void _s802FD330_0();
extern "C" void _s802FD330_1();

struct ESubModelShader {
    void RegisterMorphTarget_ESubModelShader();
};

void ESubModelShader::RegisterMorphTarget_ESubModelShader() {
}
