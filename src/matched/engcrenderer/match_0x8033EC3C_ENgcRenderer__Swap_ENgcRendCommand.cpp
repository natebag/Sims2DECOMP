// 0x8033EC3C ENgcRenderer::Swap(ENgcRendCommand (124 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); lwz 0,-26176(13); mr 31,3; cmpwi 0,0; bne 0f; bl _s8033EC3C_0; bl _s8033EC3C_1; lwz 0,0x35c(31); lwz 9,-22496(13); subf 0,0,3; divw 9,9,0; stw 0,-26804(13); stw 9,-26788(13); stw 3,0x35c(31); 0:; lwz 9,-26260(13); lwz 0,-26264(13); lfs f13,-26276(13); addi 9,9,1; lfs f0,-26272(13); stw 0,-26288(13); stfs f13,-26284(13); stfs f0,-26280(13); stw 9,-26260(13); lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"

extern "C" void _s8033EC3C_0();
extern "C" void _s8033EC3C_1();

struct ENgcRenderer {
    void Swap_ENgcRendCommand();
};

void ENgcRenderer::Swap_ENgcRendCommand() {
}
