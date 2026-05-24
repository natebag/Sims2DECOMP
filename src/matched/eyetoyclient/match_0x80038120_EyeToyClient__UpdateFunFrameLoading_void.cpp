// 0x80038120 EyeToyClient::UpdateFunFrameLoading(void) (124 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); lwz 9,-32568(13); lwz 0,-32564(13); cmpw 9,0; beq 1f; lis 31,-32692; lwz 4,-32532(13); addi 3,31,-17444; li 5,1; bl _s80038120_0; lwz 11,-32564(13); li 0,0; stw 0,-32532(13); cmpwi 11,-1; beq 0f; lis 9,-32707; rlwinm 0,11,2,0,29; addi 9,9,5888; addi 3,31,-17444; lwzx 4,9,0; bl _s80038120_1; 0:; lwz 0,-32564(13); stw 0,-32568(13); 1:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"

extern "C" void _s80038120_0();
extern "C" void _s80038120_1();

struct EyeToyClient {
    void UpdateFunFrameLoading();
};

void EyeToyClient::UpdateFunFrameLoading() {
}
