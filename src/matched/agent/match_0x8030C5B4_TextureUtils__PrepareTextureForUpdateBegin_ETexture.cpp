// 0x8030C5B4 TextureUtils::PrepareTextureForUpdateBegin(ETexture (100 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr. 11,3; bne 0f; li 3,0; b 2f; 0:; lwz 0,0x8(11); li 31,0; andi. 9,0,128; beq 1f; lwz 9,0x24(11); li 31,1; lha 3,0x60(9); lwz 0,0x64(9); add 3,11,3; mtspr 8,0; blrl; 1:; mr 3,31; 2:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void f_8030C5B4() {}
