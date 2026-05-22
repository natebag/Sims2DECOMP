// 0x803052EC EController::RemoveFilter(unsigned (188 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; mr 30,4; lwz 4,0x4(31); rlwinm 4,4,31,31,31; bl _s803052EC_0; mr 4,30; mr 3,31; bl _s803052EC_1; mr. 3,3; blt 2f; lwz 0,0x8(31); addi 6,31,12; addi 7,31,20; addi 8,31,16; cmpw 3,0; bge 1f; mulli 9,3,12; addi 9,9,24; add 10,9,31; 0:; lwz 0,0x4(10); addi 3,3,1; lwz 11,0x0(10); lwz 9,0x8(10); stw 11,-12(10); stw 0,-8(10); stw 9,-4(10); addi 10,10,12; lwz 0,0x8(31); cmpw 3,0; blt 0b; 1:; mulli 11,3,12; li 0,0; stwx 0,6,11; stwx 0,7,11; stwx 0,8,11; lwz 9,0x8(31); addi 9,9,-1; stw 9,0x8(31); 2:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s803052EC_0();
extern "C" void _s803052EC_1();
extern "C" void f_803052EC() {}
