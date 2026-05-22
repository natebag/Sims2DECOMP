// 0x80037930 EyeToyClient::FrameReadyCallback(char (64 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); lwz 0,-32572(13); mr 31,3; cmpwi 0,0; bne 0f; lwz 3,-32576(13); bl _s80037930_0; stw 31,-32572(13); 0:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s80037930_0();
extern "C" void f_80037930() {}
