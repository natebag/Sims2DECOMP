// 0x801F6484 INVTarget::InstallObjListShaders(vector<ObjSelector (236 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 23,0xc(1); stw 0,0x34(1); mr 28,4; mr 25,5; lwz 0,0x4(28); mr 31,3; lwz 9,0x0(28); subf 0,9,0; srawi 0,0,2; subf 27,25,0; cmpwi 27,12; ble 0f; li 27,12; 0:; li 29,0; cmpw 29,27; bge 4f; lis 9,-32704; lis 23,-32704; addi 24,9,-16068; li 26,0; rlwinm 30,25,2,0,29; 1:; lwz 0,0x4(28); add 9,25,29; lwz 11,0x0(28); subf 0,11,0; srawi 0,0,2; cmplw 9,0; blt 2f; addi 3,23,-26048; bl _s801F6484_0; bl _s801F6484_1; 2:; lwzx 3,11,30; bl _s801F6484_2; lwz 0,0x84(31); mr 5,3; lwz 9,0x0(31); mulli 0,0,48; cmpwi 9,0; add 0,26,0; lwzx 4,24,0; beq 3f; lwz 3,0x1c(31); cmpwi 3,0; beq 3f; lwz 6,0x7c(31); li 7,0; bl _s801F6484_3; 3:; addi 29,29,1; addi 26,26,4; addi 30,30,4; cmpw 29,27; blt 1b; 4:; lwz 0,0x34(1); mtspr 8,0; lmw 23,0xc(1); addi 1,1,48"
extern "C" void _s801F6484_0();
extern "C" void _s801F6484_1();
extern "C" void _s801F6484_2();
extern "C" void _s801F6484_3();
extern "C" void f_801F6484() {}
