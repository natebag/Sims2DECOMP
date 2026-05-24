// 0x802FBA64 ESubModelShader::VertexDataDeallocation(void (64 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); mr. 4,4; beq 0f; lwz 3,-26392(13); lwz 9,0x0(3); lha 0,0x128(9); lwz 9,0x12c(9); add 3,3,0; mtspr 8,9; blrl; 0:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"

struct ESubModelShader {
    void VertexDataDeallocation();
};

void ESubModelShader::VertexDataDeallocation() {
}
