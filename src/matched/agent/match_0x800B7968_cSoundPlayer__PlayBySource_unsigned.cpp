// 0x800B7968 cSoundPlayer::PlayBySource(unsigned (248 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stmw 28,0x28(1); stw 0,0x3c(1); mr 29,3; mr 31,4; lwz 0,0x0(29); mr 28,5; cmpwi 0,0; beq 0f; lwz 0,0x8(29); cmpwi 0,0; beq 0f; cmpwi 31,0; beq 0f; cmpwi 28,-2; beq 0f; lis 3,-32692; addi 30,1,8; addi 3,3,-14084; bl _s800B7968_0; lis 9,-32706; li 0,0; lfs f0,-25888(9); lis 4,-32693; stw 0,0x8(1); addi 4,4,-11760; stfs f0,0x8(30); stw 0,0x4(30); stw 31,0xc(1); stw 28,0x8(1); lwz 11,-26532(13); lwz 9,0x0(11); lwz 0,0x2c(9); lha 3,0x28(9); mtspr 8,0; add 3,11,3; blrl; lwz 0,0x1c(29); li 3,20; stfs f1,0x10(1); stw 0,0x20(1); bl _s800B7968_1; lwz 10,0x8(1); addi 11,3,8; lwz 9,0x8(30); lwz 0,0x4(30); stw 10,0x8(3); stw 9,0x8(11); stw 0,0x4(11); lwz 9,0x20(1); lwz 11,0x4(9); stw 9,0x0(3); stw 11,0x4(3); stw 3,0x0(11); stw 3,0x4(9); stw 3,0x18(1); 0:; lwz 0,0x3c(1); mtspr 8,0; lmw 28,0x28(1); addi 1,1,56"
extern "C" void _s800B7968_0();
extern "C" void _s800B7968_1();
extern "C" void f_800B7968() {}
