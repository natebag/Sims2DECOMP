// 0x803C06D4 InteractorModule::InteractorVisualizer::SetDefaultLights(void) (108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); li 0,0; lis 9,-32696; stw 0,0x110(3); addi 10,9,32260; stw 0,0x10c(3); addi 11,3,28; lwz 6,-28504(13); mr 4,11; lwz 8,0x7e04(9); lwz 0,0x4(10); lwz 7,0x8(10); stw 8,0x1c(3); stw 0,0x4(11); stw 7,0x8(11); lwz 9,0x70(6); lha 3,0x168(9); lwz 0,0x16c(9); add 3,6,3; mtspr 8,0; blrl; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void f_803C06D4() {}
