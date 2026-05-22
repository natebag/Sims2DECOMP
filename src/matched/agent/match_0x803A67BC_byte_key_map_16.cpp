// 0x803A67BC byte_key_map<16, (200 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 28,3; mr 27,4; addi 29,28,4; lwz 31,0x4(28); lwz 30,0x4(29); cmpw 31,30; beq 3f; 0:; lwz 3,0xc(31); addi 9,31,12; cmpwi 3,0; beq 2f; lwz 0,0xc(9); subf 0,3,0; rlwinm 4,0,0,0,30; cmplwi 4,128; ble 1f; bl _s803A67BC_0; b 2f; 1:; bl _s803A67BC_1; 2:; addi 31,31,28; cmpw 31,30; bne 0b; 3:; lwz 3,0x0(29); cmpwi 3,0; beq 5f; lwz 0,0xc(29); lis 9,-18725; ori 9,9,28087; subf 0,3,0; mullw 0,0,9; srawi 0,0,2; mulli 4,0,28; cmplwi 4,128; ble 4f; bl _s803A67BC_2; b 5f; 4:; bl _s803A67BC_3; 5:; andi. 0,27,1; beq 6f; mr 3,28; bl _s803A67BC_4; 6:; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s803A67BC_0();
extern "C" void _s803A67BC_1();
extern "C" void _s803A67BC_2();
extern "C" void _s803A67BC_3();
extern "C" void _s803A67BC_4();
extern "C" void f_803A67BC() {}
