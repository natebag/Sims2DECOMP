// 0x800BB8CC HouseImpl::LoadFile(iResFile (540 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 28,0x18(1); stw 0,0x2c(1); lis 9,-32706; lwz 11,-21496(13); lfs f0,-25120(9); mr 30,3; mr 31,4; mr 28,5; stfs f0,0xc(1); li 4,20; stfs f0,0x8(1); lwz 9,0x0(11); lha 3,0x30(9); lwz 0,0x34(9); add 3,11,3; mtspr 8,0; blrl; mr 29,3; lwz 5,-32032(13); lwz 3,-21496(13); mr 4,31; lha 6,-32036(13); addi 7,1,16; bl _s800BB8CC_0; cmpwi 3,0; beq 0f; lwz 3,-21496(13); mr 4,31; lwz 5,-32032(13); li 6,0; li 7,0; bl _s800BB8CC_1; li 0,0; stw 0,0x10(1); 0:; lwz 11,-21496(13); mr 5,29; li 4,20; lwz 9,0x0(11); lwz 0,0x3c(9); lha 3,0x38(9); mtspr 8,0; add 3,11,3; blrl; lis 4,-32706; addi 3,30,24; addi 4,4,-25124; bl _s800BB8CC_2; lha 6,-32034(13); addi 7,1,20; lwz 5,-32028(13); mr 4,31; mr 3,30; bl _s800BB8CC_3; lwz 11,-21496(13); li 5,0; li 4,9; lwz 9,0x0(11); lwz 0,0x3c(9); lha 3,0x38(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,-21476(13); li 4,0; lwz 9,0x0(11); lwz 0,0x124(9); lha 3,0x120(9); mtspr 8,0; add 3,11,3; blrl; stw 3,0x14(30); lwz 11,-21484(13); lwz 9,0x0(11); lwz 0,0x6c(9); lha 3,0x68(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,-21488(13); mr 4,31; lwz 5,0x10(1); lwz 9,0x0(11); lwz 0,0x1c(9); lha 3,0x18(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,-21484(13); mr 4,31; lwz 9,0x0(11); lwz 0,0x2c(9); lha 3,0x28(9); mtspr 8,0; add 3,11,3; blrl; mr 4,31; li 3,147; bl _s800BB8CC_4; li 4,0; li 3,132; bl _s800BB8CC_5; li 4,0; li 3,145; bl _s800BB8CC_6; li 4,0; li 3,228; bl _s800BB8CC_7; lwz 11,-21496(13); li 4,0; lwz 9,0x0(11); lha 3,0xa0(9); lwz 0,0xa4(9); add 3,11,3; mtspr 8,0; blrl; mr 4,3; li 3,214; bl _s800BB8CC_8; li 4,0; li 3,217; bl _s800BB8CC_9; lwz 3,-21472(13); bl _s800BB8CC_10; cmpwi 28,0; beq 1f; lwz 0,0x10(1); stw 0,0x0(28); 1:; li 3,0; lwz 0,0x2c(1); mtspr 8,0; lmw 28,0x18(1); addi 1,1,40"

extern "C" void _s800BB8CC_0();
extern "C" void _s800BB8CC_1();
extern "C" void _s800BB8CC_2();
extern "C" void _s800BB8CC_3();
extern "C" void _s800BB8CC_4();
extern "C" void _s800BB8CC_5();
extern "C" void _s800BB8CC_6();
extern "C" void _s800BB8CC_7();
extern "C" void _s800BB8CC_8();
extern "C" void _s800BB8CC_9();
extern "C" void _s800BB8CC_10();

struct HouseImpl {
    void LoadFile_iResFile();
};

void HouseImpl::LoadFile_iResFile() {
}
