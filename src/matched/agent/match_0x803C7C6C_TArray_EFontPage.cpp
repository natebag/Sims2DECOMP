// 0x803C7C6C TArray<EFontPage (104 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 29,3; lwz 31,0x4(29); lwz 30,0x0(29); b 1f; 0:; lwz 3,0x0(30); addi 30,30,4; lwz 9,0x0(3); lha 0,0x8(9); lwz 9,0xc(9); add 3,3,0; mtspr 8,9; blrl; 1:; cmpwi 31,0; addi 31,31,-1; bne 0b; mr 3,29; bl _s803C7C6C_0; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s803C7C6C_0();
extern "C" void f_803C7C6C() {}
