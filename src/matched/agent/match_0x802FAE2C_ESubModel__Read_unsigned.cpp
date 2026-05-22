// 0x802FAE2C ESubModel::Read(unsigned (244 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 24,0x10(1); stw 0,0x34(1); mr 30,3; mr 31,4; mr 26,5; li 5,4; mr 24,31; addi 3,30,12; addi 31,31,4; bl _s802FAE2C_0; li 28,0; mr 4,31; addi 3,1,8; li 5,4; addi 31,31,4; bl _s802FAE2C_1; mr 3,30; li 4,0; li 5,0; bl _s802FAE2C_2; lwz 4,0x8(1); mr 3,30; li 5,0; bl _s802FAE2C_3; lwz 0,0x8(1); cmpw 28,0; bge 2f; li 25,1; li 27,0; 0:; lwz 3,0x14(30); mulli 29,28,112; cmpwi 3,0; beq 1f; bl _s802FAE2C_4; cmpwi 3,0; beq 1f; lwz 9,0x0(30); add 9,9,27; stw 25,0x4(9); 1:; lwz 9,0x0(30); mr 4,31; mr 5,26; addi 28,28,1; add 9,9,29; addi 27,27,112; stw 30,0x20(9); lwz 3,0x0(30); add 3,3,29; bl _s802FAE2C_5; lwz 0,0x8(1); add 31,31,3; cmpw 28,0; blt 0b; 2:; subf 3,24,31; lwz 0,0x34(1); mtspr 8,0; lmw 24,0x10(1); addi 1,1,48"
extern "C" void _s802FAE2C_0();
extern "C" void _s802FAE2C_1();
extern "C" void _s802FAE2C_2();
extern "C" void _s802FAE2C_3();
extern "C" void _s802FAE2C_4();
extern "C" void _s802FAE2C_5();
extern "C" void f_802FAE2C() {}
