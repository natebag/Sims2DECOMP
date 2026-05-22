// 0x80216488 InteractorModule::InteractorVisualizer::DrawRoomPreview(InteractorModule::WallManipulator (584 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-120(1); mfspr 0,8; stfd f30,0x68(1); stfd f31,0x70(1); stmw 25,0x4c(1); stw 0,0x7c(1); lis 11,-32704; addi 9,1,40; lfs f0,-10400(11); mr 27,9; addi 11,1,56; mr 25,3; stfs f0,0x8(9); mr 31,4; stfs f0,0x4(9); mr 28,11; stfs f0,0x28(1); lis 9,-32704; stfs f0,0x8(11); stfs f0,0x4(11); lfs f30,-10396(9); stfs f0,0x38(1); bl _s80216488_0; mr. 3,3; beq 2f; lwz 0,0xc4(31); andi. 9,0,128; beq 0f; lis 4,-30309; ori 4,4,41963; b 1f; 0:; lis 4,30212; ori 4,4,49507; 1:; bl _s80216488_1; mr 26,3; cmpwi 26,0; beq 2f; lwz 0,0x20(31); addi 9,31,32; lwz 8,0x8(9); addi 30,1,24; lwz 10,0x4(9); addi 11,31,96; stw 0,0x18(1); addi 29,1,8; lfs f31,-21100(13); mr 3,31; lwz 9,0x60(31); stw 8,0x8(30); stw 10,0x4(30); lwz 10,0x8(11); lwz 0,0x4(11); stw 9,0x8(1); stw 10,0x8(29); stw 0,0x4(29); stw 0,0x4(27); lwz 9,0x8(1); lfs f0,0x8(1); lfs f13,0x1c(1); stw 9,0x28(1); stw 10,0x8(27); stfs f0,0x38(1); stfs f13,0x3c(1); bl _s80216488_2; mr 7,3; fmr f1,f31; mr 4,26; mr 5,27; mr 6,28; fmr f2,f30; mr 3,25; bl _s80216488_3; lwz 11,0x38(1); mr 3,31; lwz 0,0x4(28); lwz 9,0x8(28); stw 11,0x28(1); stw 0,0x4(27); stw 9,0x8(27); lfs f31,-21100(13); lwz 11,0x18(1); lwz 9,0x8(30); lwz 0,0x4(30); stw 11,0x38(1); stw 0,0x4(28); stw 9,0x8(28); bl _s80216488_4; mr 7,3; fmr f1,f31; mr 4,26; mr 5,27; mr 6,28; fmr f2,f30; mr 3,25; bl _s80216488_5; lwz 11,0x38(1); mr 3,31; lwz 0,0x4(28); lwz 9,0x8(28); lfs f0,0x18(1); lfs f13,0xc(1); stw 11,0x28(1); stw 0,0x4(27); stw 9,0x8(27); stfs f0,0x38(1); stfs f13,0x3c(1); lfs f31,-21100(13); bl _s80216488_6; mr 7,3; fmr f1,f31; mr 4,26; mr 5,27; mr 6,28; fmr f2,f30; mr 3,25; bl _s80216488_7; lwz 11,0x38(1); mr 3,31; lwz 0,0x4(28); lwz 9,0x8(28); stw 11,0x28(1); stw 0,0x4(27); stw 9,0x8(27); lfs f31,-21100(13); lwz 11,0x8(1); lwz 9,0x8(29); lwz 0,0x4(29); stw 11,0x38(1); stw 0,0x4(28); stw 9,0x8(28); bl _s80216488_8; mr 7,3; mr 4,26; mr 3,25; mr 5,27; mr 6,28; fmr f1,f31; fmr f2,f30; bl _s80216488_9; 2:; lwz 0,0x7c(1); mtspr 8,0; lmw 25,0x4c(1); lfd f30,0x68(1); lfd f31,0x70(1); addi 1,1,120"
extern "C" void _s80216488_0();
extern "C" void _s80216488_1();
extern "C" void _s80216488_2();
extern "C" void _s80216488_3();
extern "C" void _s80216488_4();
extern "C" void _s80216488_5();
extern "C" void _s80216488_6();
extern "C" void _s80216488_7();
extern "C" void _s80216488_8();
extern "C" void _s80216488_9();
extern "C" void f_80216488() {}
