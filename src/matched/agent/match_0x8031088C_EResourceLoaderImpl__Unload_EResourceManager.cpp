// 0x8031088C EResourceLoaderImpl::Unload(EResourceManager (172 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 30,3; mr 29,5; mr. 28,4; beq 1f; cmpwi 29,0; beq 1f; lwz 9,0x0(30); lha 3,0x28(9); lwz 0,0x2c(9); add 3,30,3; mtspr 8,0; blrl; mr. 31,3; beq 0f; mr 3,28; mr 4,29; li 5,1; bl _s8031088C_0; b 1f; 0:; li 3,40; bl _s8031088C_1; bl _s8031088C_2; mr 9,3; li 0,4; stw 0,0x0(9); mr 3,30; stw 29,0x8(9); mr 4,9; stw 28,0x4(9); stw 31,0x20(9); stw 31,0xc(9); stw 31,0x10(9); stw 31,0x14(9); bl _s8031088C_3; 1:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s8031088C_0();
extern "C" void _s8031088C_1();
extern "C" void _s8031088C_2();
extern "C" void _s8031088C_3();
extern "C" void f_8031088C() {}
