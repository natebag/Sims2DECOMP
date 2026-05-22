// 0x80219074 InteractorModule::ObjectManipulator::OnStart(InteractorModule::Interactor::InteractorParams (380 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-96(1); mfspr 0,8; stmw 28,0x50(1); stw 0,0x64(1); mr 28,4; lis 9,-32704; lwz 0,0x4(28); mr 31,3; addi 8,9,-9872; addi 11,1,8; stw 0,0x0(31); li 9,24; addi 29,1,48; 0:; lwz 0,0x0(8); addic. 9,9,-24; stw 0,0x0(11); lwz 0,0x4(8); stw 0,0x4(11); lwz 0,0x8(8); stw 0,0x8(11); lwz 0,0xc(8); stw 0,0xc(11); lwz 0,0x10(8); stw 0,0x10(11); lwz 0,0x14(8); addi 8,8,24; stw 0,0x14(11); addi 11,11,24; bne 0b; lwz 0,0x0(8); lis 9,-32704; addi 9,9,-9832; mr 10,29; stw 0,0x0(11); li 7,24; lwz 0,0x4(8); addi 30,31,8; stw 0,0x4(11); lwz 0,0x8(8); stw 0,0x8(11); lwz 0,0xc(8); stw 0,0xc(11); 1:; lwz 0,0x0(9); addic. 7,7,-24; stw 0,0x0(10); lwz 0,0x4(9); stw 0,0x4(10); lwz 0,0x8(9); stw 0,0x8(10); lwz 0,0xc(9); stw 0,0xc(10); lwz 0,0x10(9); stw 0,0x10(10); lwz 0,0x14(9); addi 9,9,24; stw 0,0x14(10); addi 10,10,24; bne 1b; lwz 0,0x0(9); stw 0,0x0(10); lwz 0,0x4(9); stw 0,0x4(10); bl _s80219074_0; lwz 10,0x60(31); mr 9,29; lwz 4,0x4(28); mr 5,31; li 6,5; addi 7,1,8; li 8,4; bl _s80219074_1; lwz 3,0x0(31); bl _s80219074_2; bl _s80219074_3; lwz 4,0x0(31); bl _s80219074_4; mr 9,3; lwz 11,0x43c(9); mr 3,30; addi 9,9,1084; lwz 10,0x8(9); lwz 0,0x4(9); stw 11,0x8(31); stw 0,0x4(30); stw 10,0x8(30); bl _s80219074_5; lis 9,-32704; lfs f0,-9800(9); stfs f0,0x54(31); stfs f0,0x50(31); lwz 0,0x64(1); mtspr 8,0; lmw 28,0x50(1); addi 1,1,96"
extern "C" void _s80219074_0();
extern "C" void _s80219074_1();
extern "C" void _s80219074_2();
extern "C" void _s80219074_3();
extern "C" void _s80219074_4();
extern "C" void _s80219074_5();
extern "C" void f_80219074() {}
