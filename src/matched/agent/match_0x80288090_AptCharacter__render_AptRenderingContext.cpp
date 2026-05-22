// 0x80288090 AptCharacter::render(AptRenderingContext (144 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; mfcr 12; stmw 28,0x10(1); stw 0,0x24(1); stw 12,0xc(1); mr. 31,6; mr 29,3; mr 30,4; mr 28,5; mcrf cr4,cr0; beq cr4,0f; mr 3,30; bl _s80288090_0; mr 4,31; mr 3,30; bl _s80288090_1; 0:; lwz 0,0x0(29); cmpwi 0,1; bne 1f; lis 9,-32694; lwz 3,0x18(29); lwz 0,-16160(9); mr 4,28; mtspr 8,0; blrl; 1:; beq cr4,2f; mr 3,30; bl _s80288090_2; 2:; lwz 0,0x24(1); lwz 12,0xc(1); mtspr 8,0; lmw 28,0x10(1); mtcrf 8,12; addi 1,1,32"
extern "C" void _s80288090_0();
extern "C" void _s80288090_1();
extern "C" void _s80288090_2();
extern "C" void f_80288090() {}
