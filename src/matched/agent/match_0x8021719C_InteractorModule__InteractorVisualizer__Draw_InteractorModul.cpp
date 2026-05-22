// 0x8021719C InteractorModule::InteractorVisualizer::Draw(InteractorModule::DirectInteractor (240 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); lwz 30,0x0(4); li 29,0; cmplwi 30,1; bgt 0f; rlwinm 0,30,2,0,29; addi 9,13,-21420; lwzx 0,9,0; cmpwi 0,0; beq 0f; mr 29,0; 0:; lis 28,-32697; mr 4,30; addi 3,28,24012; bl _s8021719C_0; mr 31,3; cmpwi 29,0; beq 1f; mr 3,29; mr 4,30; bl _s8021719C_1; cmpwi 31,0; beq 1f; lwz 3,0x0(31); lwz 9,0x4(3); lha 0,0x1a8(9); lwz 9,0x1ac(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; beq 1f; lwz 3,0x0(31); li 4,34; lwz 9,0x4(3); lha 0,0x260(9); lwz 9,0x264(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; bne 1f; addi 9,28,24012; rlwinm 10,30,2,0,29; addi 9,9,280; lwzx 11,9,10; lwz 0,0x160(11); cmpwi 0,8; beq 1f; lwz 4,-28504(13); mr 3,29; bl _s8021719C_2; 1:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s8021719C_0();
extern "C" void _s8021719C_1();
extern "C" void _s8021719C_2();
extern "C" void f_8021719C() {}
