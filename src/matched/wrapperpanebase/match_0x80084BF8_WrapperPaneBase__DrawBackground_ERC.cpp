// 0x80084BF8 WrapperPaneBase::DrawBackground(ERC (652 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-96(1); mfspr 0,8; stfd f29,0x48(1); stfd f30,0x50(1); stfd f31,0x58(1); stmw 24,0x28(1); stw 0,0x64(1); lis 9,-32697; lis 11,-32702; addi 28,9,24012; mr 31,3; mr 27,4; addi 25,11,15952; li 29,0; lis 24,-32707; li 26,0; 0:; addi 9,31,64; lwzx 30,9,26; cmpwi 30,0; beq 3f; li 0,256; lwz 9,0x4(31); slw 0,0,29; and. 11,9,0; beq 3f; lwz 0,0x4(30); andis. 9,0,128; beq 3f; andis. 11,0,256; beq 3f; andis. 9,0,512; beq 3f; lwz 8,0x38(31); cmpwi 8,0; beq 1f; lwz 3,0xb4(28); addi 4,24,29260; li 5,0; li 6,0; li 7,1; crxor 6,6,6; bl _s80084BF8_0; b 2f; 1:; lis 8,-32707; lwz 3,0xb4(28); addi 8,8,29280; addi 4,24,29260; li 5,0; li 6,0; li 7,1; crxor 6,6,6; bl _s80084BF8_1; 2:; lwz 3,0xb4(28); lis 4,-32707; lwz 8,0x0(25); addi 4,4,29320; li 5,0; li 6,0; li 7,1; crxor 6,6,6; bl _s80084BF8_2; lwz 3,0xb4(28); lis 4,-32707; addi 4,4,29300; li 5,0; li 6,0; li 7,0; crxor 6,6,6; bl _s80084BF8_3; lwz 0,0x4(30); rlwinm 0,0,0,9,7; stw 0,0x4(30); 3:; addi 29,29,1; addi 25,25,4; addi 26,26,4; cmpwi 29,6; ble 0b; lwz 0,0x4(31); xori 0,0,1; andi. 9,0,1; bne 7f; lwz 9,0x18(31); cmpwi 9,0; beq 7f; lwz 3,0x14(9); cmpwi 3,0; beq 4f; mr 11,3; b 5f; 4:; lwz 9,0x18(9); li 11,0; cmpwi 9,0; beq 5f; lwz 11,0x14(9); 5:; lwz 9,0xf0(11); mr 4,27; li 5,0; lha 3,0x10(9); lwz 0,0x14(9); add 3,11,3; mtspr 8,0; blrl; lfs f13,0x30(31); lis 9,-32707; lfs f0,0x2c(31); lfs f29,0x7294(9); fmuls f30,f13,f0; fcmpu 0,f30,f29; ble 7f; lis 9,-32707; lfs f31,0x7298(9); fcmpu 0,f30,f31; mfcr 29; beq 6f; lwz 9,0x70(27); li 4,64; li 5,0; lha 3,0x140(9); lwz 0,0x144(9); add 3,27,3; mtspr 8,0; blrl; 6:; lwz 30,0x70(27); addi 11,1,8; addi 10,1,16; addi 9,1,24; lha 3,0x188(30); addi 5,31,36; stfs f29,0x8(1); mr 6,11; stfs f31,0x4(11); add 3,27,3; stfs f31,0x10(1); mr 7,10; stfs f29,0x4(10); mr 8,9; stfs f31,0x18(1); fmr f1,f29; stfs f31,0x8(9); addi 4,31,28; stfs f31,0x4(9); stfs f30,0x24(1); lwz 0,0x18c(30); mtspr 8,0; blrl; mtcrf 128,29; beq 7f; lwz 9,0x70(27); li 4,64; li 5,0; lha 3,0x148(9); lwz 0,0x14c(9); add 3,27,3; mtspr 8,0; blrl; 7:; lwz 0,0x64(1); mtspr 8,0; lmw 24,0x28(1); lfd f29,0x48(1); lfd f30,0x50(1); lfd f31,0x58(1); addi 1,1,96"

extern "C" void _s80084BF8_0();
extern "C" void _s80084BF8_1();
extern "C" void _s80084BF8_2();
extern "C" void _s80084BF8_3();

struct WrapperPaneBase {
    void DrawBackground();
};

void WrapperPaneBase::DrawBackground() {
}
