// 0x8035A2DC EConfig::Open(char (328 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-4144(1); mfspr 0,8; stmw 27,0x101c(1); stw 0,0x1034(1); mr 31,3; mr 29,4; li 6,0; li 5,0; li 4,1; bl _s8035A2DC_0; addi 30,1,4112; mr 4,29; addi 3,31,4; mr 27,30; bl _s8035A2DC_1; lis 3,-32694; lwz 5,0x4(31); lis 6,-32702; addi 3,3,-10620; addi 6,6,11424; mr 4,30; lis 7,-32768; lis 8,-32768; li 9,0; bl _s8035A2DC_2; cmpwi 3,0; bne 0f; li 3,0; b 3f; 0:; addi 28,1,4104; b 2f; 1:; li 3,4; bl _s8035A2DC_3; mr 30,3; bl _s8035A2DC_4; mr 4,30; addi 3,31,8; bl _s8035A2DC_5; mr 29,3; addi 4,1,8; mr 3,30; bl _s8035A2DC_6; mr 3,30; li 4,61; li 5,0; bl _s8035A2DC_7; cmpwi 3,-1; beq 2f; lwz 9,0x0(30); lbz 0,0x0(9); extsb 0,0; cmpwi 0,59; beq 2f; cmpwi 0,35; beq 2f; mr 5,3; mr 4,30; mr 3,28; bl _s8035A2DC_8; lwz 4,0x1008(1); mr 5,29; addi 3,31,20; bl _s8035A2DC_9; lwz 4,0x1008(1); mr 3,28; bl _s8035A2DC_10; 2:; lwz 5,0x1010(1); addi 3,1,8; li 4,4095; bl _s8035A2DC_11; cmpwi 3,0; bne 1b; lis 3,-32694; mr 4,27; addi 3,3,-10620; bl _s8035A2DC_12; li 3,1; 3:; lwz 0,0x1034(1); mtspr 8,0; lmw 27,0x101c(1); addi 1,1,4144"
extern "C" void _s8035A2DC_0();
extern "C" void _s8035A2DC_1();
extern "C" void _s8035A2DC_2();
extern "C" void _s8035A2DC_3();
extern "C" void _s8035A2DC_4();
extern "C" void _s8035A2DC_5();
extern "C" void _s8035A2DC_6();
extern "C" void _s8035A2DC_7();
extern "C" void _s8035A2DC_8();
extern "C" void _s8035A2DC_9();
extern "C" void _s8035A2DC_10();
extern "C" void _s8035A2DC_11();
extern "C" void _s8035A2DC_12();
extern "C" void f_8035A2DC() {}
