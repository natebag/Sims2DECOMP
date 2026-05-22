// 0x8031F040 ERShader::RemoveFromUpdateList(void) (220 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lwz 0,0x54(31); cmpwi 0,0; beq 4f; lis 3,-32693; li 4,-1; lwz 9,0x17b8(3); addi 3,3,6072; lha 0,0x10(9); lwz 9,0x14(9); add 3,0,3; mtspr 8,9; blrl; lwz 11,0x54(31); lwz 0,-22620(13); cmpw 0,11; bne 0f; lwz 0,0x8(11); stw 0,-22620(13); b 1f; 0:; lwz 9,0x4(11); lwz 0,0x8(11); stw 0,0x8(9); 1:; lwz 0,-22616(13); cmpw 0,11; bne 2f; lwz 0,0x4(11); stw 0,-22616(13); b 3f; 2:; lwz 0,0x4(11); lwz 9,0x8(11); stw 0,0x4(9); 3:; lis 3,-32693; lwz 9,0x17b8(3); addi 3,3,6072; lha 0,0x18(9); lwz 9,0x1c(9); add 3,0,3; mtspr 8,9; blrl; lis 3,-32692; lwz 4,0x54(31); addi 3,3,-17444; bl _s8031F040_0; li 0,0; stw 0,0x54(31); 4:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s8031F040_0();
extern "C" void f_8031F040() {}
