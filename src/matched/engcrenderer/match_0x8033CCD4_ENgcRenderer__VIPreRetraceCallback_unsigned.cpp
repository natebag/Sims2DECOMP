// 0x8033CCD4 ENgcRenderer::VIPreRetraceCallback(unsigned (280 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); lwz 11,-25912(13); mr 31,3; lwz 0,-26176(13); lwz 9,0x340(11); cmpwi 0,0; addi 9,9,1; stw 9,0x340(11); beq 0f; lwz 0,-26148(13); cmpwi 0,0; beq 0f; lwz 0,-26136(13); lwz 9,-26292(13); add 0,0,9; cmplw 31,0; ble 0f; lwz 3,-26144(13); bl _s8033CCD4_0; bl _s8033CCD4_1; lis 3,-32690; lwz 9,-25824(3); addi 3,3,-25824; lha 0,0x18(9); lwz 9,0x1c(9); add 3,0,3; mtspr 8,9; blrl; li 0,0; lwz 3,-26140(13); stw 0,-26148(13); bl _s8033CCD4_2; lis 11,-32691; lwz 10,-22496(13); addi 11,11,21688; lwz 8,-25912(13); lwz 0,0x35c(11); lwz 9,0x344(8); subf 0,0,31; divw 10,10,0; stw 0,-26804(13); addi 9,9,1; stw 9,0x344(8); stw 31,0x35c(11); stw 31,-26136(13); stw 10,-26788(13); 0:; addi 6,13,-22521; addi 7,13,-22520; addi 4,13,-22523; addi 5,13,-22522; addi 3,13,-22524; bl _s8033CCD4_3; bl _s8033CCD4_4; addi 4,13,-22516; addi 5,13,-22512; bl _s8033CCD4_5; bl _s8033CCD4_6; lwz 0,-26128(13); stw 3,-26132(13); cmpwi 0,0; beq 1f; bl _s8033CCD4_7; 1:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"

extern "C" void _s8033CCD4_0();
extern "C" void _s8033CCD4_1();
extern "C" void _s8033CCD4_2();
extern "C" void _s8033CCD4_3();
extern "C" void _s8033CCD4_4();
extern "C" void _s8033CCD4_5();
extern "C" void _s8033CCD4_6();
extern "C" void _s8033CCD4_7();

struct ENgcRenderer {
    void VIPreRetraceCallback();
};

void ENgcRenderer::VIPreRetraceCallback() {
}
