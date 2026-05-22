// 0x8004E618 ISimsObjectModel::ChageShader(unsigned (136 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; mr 29,4; lwz 0,0x120(31); mr 30,5; cmpwi 0,0; beq 1f; lwz 3,0x41c(31); cmpwi 3,0; beq 0f; bl _s8004E618_0; li 0,0; stw 0,0x41c(31); 0:; cmpwi 30,0; beq 1f; lis 3,-32692; mr 4,30; li 5,0; addi 3,3,-17444; li 6,0; bl _s8004E618_1; stw 3,0x41c(31); mr 4,29; mr 3,31; mr 5,30; bl _s8004E618_2; 1:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8004E618_0();
extern "C" void _s8004E618_1();
extern "C" void _s8004E618_2();
extern "C" void f_8004E618() {}
