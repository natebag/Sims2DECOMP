// 0x801F6254 INVTarget::InstallWallShaders(vector<InteractorModule::WallData, (324 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 23,0xc(1); stw 0,0x34(1); mr 26,4; mr 25,5; lwz 0,0x4(26); addi 11,25,-1; lwz 9,0x0(26); mr 31,3; subf 0,9,0; srawi 0,0,3; subf 27,11,0; cmpwi 27,12; ble 0f; li 27,12; 0:; li 0,0; cmpwi 25,0; bne 2f; lwz 0,0x84(31); lis 9,-32704; lwz 11,0x0(31); addi 9,9,-16068; mulli 0,0,48; cmpwi 11,0; lwzx 4,9,0; beq 1f; lwz 3,0x1c(31); cmpwi 3,0; beq 1f; lis 5,-8422; lwz 6,0x7c(31); ori 5,5,36483; li 7,0; bl _s801F6254_0; 1:; li 0,1; addi 27,27,-1; 2:; li 28,0; cmpw 28,27; bge 6f; lis 9,-32704; rlwinm 29,0,2,0,29; addi 23,9,-16068; lis 24,-32704; rlwinm 30,25,3,0,28; 3:; lwz 0,0x4(26); add 9,25,28; lwz 3,0x0(26); subf 0,3,0; srawi 0,0,3; cmplw 9,0; blt 4f; addi 3,24,-26048; bl _s801F6254_1; bl _s801F6254_2; 4:; add 3,3,30; bl _s801F6254_3; lwz 0,0x84(31); mr 5,3; lwz 9,0x0(31); mulli 0,0,48; cmpwi 9,0; add 0,29,0; lwzx 4,23,0; beq 5f; lwz 3,0x1c(31); cmpwi 3,0; beq 5f; lwz 6,0x7c(31); li 7,0; bl _s801F6254_4; 5:; addi 28,28,1; addi 29,29,4; addi 30,30,8; cmpw 28,27; blt 3b; 6:; lwz 0,0x34(1); mtspr 8,0; lmw 23,0xc(1); addi 1,1,48"
extern "C" void _s801F6254_0();
extern "C" void _s801F6254_1();
extern "C" void _s801F6254_2();
extern "C" void _s801F6254_3();
extern "C" void _s801F6254_4();
extern "C" void f_801F6254() {}
