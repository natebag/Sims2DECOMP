// 0x8031CA58 ERShader::DeallocateIncomingShader(void) (160 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lwz 3,0x1c(31); cmpwi 3,0; beq 0f; bl _s8031CA58_0; li 0,0; stw 0,0x1c(31); 0:; lwz 0,0x58(31); andi. 9,0,4; beq 1f; lwz 4,0x5c(31); lis 3,-32692; addi 3,3,-17444; bl _s8031CA58_1; lwz 0,0x58(31); li 9,0; stw 9,0x5c(31); rlwinm 0,0,0,30,28; stw 0,0x58(31); 1:; lwz 0,0x58(31); lis 3,-32692; lwz 4,0x68(31); addi 3,3,-17444; rlwinm 0,0,0,29,27; stw 0,0x58(31); bl _s8031CA58_2; lis 9,-32702; li 0,0; lfs f0,0xa2c(9); stw 0,0x68(31); stfs f0,0x60(31); lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"

extern "C" void _s8031CA58_0();
extern "C" void _s8031CA58_1();
extern "C" void _s8031CA58_2();

struct ERShader {
    void DeallocateIncomingShader();
};

void ERShader::DeallocateIncomingShader() {
}
