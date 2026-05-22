// 0x8016FA20 CasSimRenderer::UpdateRepShaders(int) (144 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-568(1); mfspr 0,8; stmw 28,0x228(1); stw 0,0x23c(1); mr 30,3; mr 28,4; addi 3,1,8; addi 29,30,112; bl _s8016FA20_0; li 31,0; lwz 3,0x0(30); bl _s8016FA20_1; lwz 4,0x84(3); addi 3,1,8; bl _s8016FA20_2; 0:; lwz 5,0x0(29); addi 29,29,4; cmpwi 5,0; beq 1f; addi 3,1,8; mr 4,31; bl _s8016FA20_3; 1:; addi 31,31,1; cmpwi 31,25; ble 0b; mr 4,28; addi 3,1,8; bl _s8016FA20_4; addi 3,1,8; li 4,2; bl _s8016FA20_5; lwz 0,0x23c(1); mtspr 8,0; lmw 28,0x228(1); addi 1,1,568"
extern "C" void _s8016FA20_0();
extern "C" void _s8016FA20_1();
extern "C" void _s8016FA20_2();
extern "C" void _s8016FA20_3();
extern "C" void _s8016FA20_4();
extern "C" void _s8016FA20_5();
extern "C" void f_8016FA20() {}
