// 0x8021F208 InteractorModule::SocialModeInteractor::OnStart(InteractorModule::Interactor::InteractorParams (200 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); lwz 0,0x4(4); mr 30,3; stw 0,0x0(30); bl _s8021F208_0; lwz 29,-26524(13); lwz 4,0x0(30); mr 3,29; bl _s8021F208_1; mr 4,3; mr 3,29; bl _s8021F208_2; mr 29,3; lis 4,-241; lis 5,-32704; li 6,100; addi 5,5,-8472; ori 4,4,24563; bl _s8021F208_3; mr 0,3; li 5,2048; mr 4,0; stw 0,0x64(30); mr 3,29; bl _s8021F208_4; lwz 4,0x64(30); li 5,9; mr 3,29; bl _s8021F208_5; lis 5,-32704; mr 3,29; addi 5,5,-8388; li 4,0; li 6,100; bl _s8021F208_6; stw 3,0x68(30); lwz 9,0x5c(30); lha 3,0x78(9); lwz 0,0x7c(9); add 3,30,3; mtspr 8,0; blrl; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8021F208_0();
extern "C" void _s8021F208_1();
extern "C" void _s8021F208_2();
extern "C" void _s8021F208_3();
extern "C" void _s8021F208_4();
extern "C" void _s8021F208_5();
extern "C" void _s8021F208_6();
extern "C" void f_8021F208() {}
