// 0x80320C00 ERTexture::Deallocate(void) (80 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lwz 11,-26392(13); mr 30,3; lwz 4,0x14(30); lwz 9,0x0(11); lwz 0,0xc4(9); lha 3,0xc0(9); mtspr 8,0; add 3,11,3; blrl; li 0,0; stw 0,0x14(30); lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void f_80320C00() {}
