// 0x8016AD14 CasSimPartsS2C::GetNumTattooTextures(eTattooTextureTypeS2C) (72 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-608(1); mfspr 0,8; stw 0,0x264(1); lwz 0,0x4(3); cmpwi 0,0; beq 0f; cmpwi 4,2; bgt 0f; cmpwi 4,0; blt 0f; addi 5,1,8; bl _s8016AD14_0; b 1f; 0:; li 3,0; 1:; lwz 0,0x264(1); mtspr 8,0; addi 1,1,608"
extern "C" void _s8016AD14_0();
extern "C" void f_8016AD14() {}
