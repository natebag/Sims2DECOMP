// 0x803A4E38 _Rb_tree<int, (616 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stmw 27,0x24(1); stw 0,0x3c(1); mr 31,4; mr 28,5; lwz 9,0x4(31); mr 29,3; lwz 8,0x0(28); mr 30,6; lwz 0,0x8(9); cmpw 8,0; bne 4f; lwz 0,0x8(31); cmpwi 0,0; bne 0f; mr 5,30; addi 3,1,8; bl _s803A4E38_0; lwz 0,0x8(1); b 15f; 0:; lwz 0,0x0(30); mr 5,8; lwz 3,0x10(8); mr 8,0; cmpw 0,3; blt 12f; cmpw 3,8; blt 1f; stw 5,0x0(29); b 16f; 1:; mr 3,5; stw 5,0x8(1); bl _s803A4E38_1; lwz 0,0x4(31); stw 3,0x8(1); cmpw 3,0; bne 2f; lwz 6,0x0(28); b 10f; 2:; lwz 9,0x0(30); mr 5,3; lwz 0,0x10(3); cmpw 9,0; bge 3f; lwz 6,0x0(28); lwz 0,0xc(6); cmpwi 0,0; beq 10f; b 12f; 3:; mr 4,31; mr 5,30; addi 3,1,16; bl _s803A4E38_2; lwz 0,0x10(1); b 15f; 4:; cmpw 8,9; bne 6f; lwz 6,0xc(8); lwz 9,0x0(30); lwz 0,0x10(6); cmpw 0,9; bge 5f; mr 4,31; mr 7,30; mr 3,29; li 5,0; bl _s803A4E38_3; b 16f; 5:; mr 4,31; mr 5,30; addi 3,1,8; bl _s803A4E38_4; lwz 0,0x8(1); b 15f; 6:; mr 3,8; stw 8,0x8(1); bl _s803A4E38_5; lwz 11,0x0(28); lwz 9,0x0(30); stw 3,0x8(1); lwz 0,0x10(11); cmpw cr7,9,0; mfcr 27; rlwinm. 27,27,29,31,31; beq 7f; lwz 0,0x10(3); mr 5,3; cmpw 0,9; bge 7f; lwz 0,0xc(5); cmpwi 0,0; beq 9f; mr 5,11; b 12f; 7:; lwz 0,0x0(28); mr 3,0; stw 0,0x10(1); bl _s803A4E38_6; xori 11,27,1; stw 3,0x10(1); cmpwi 27,0; bne 13f; lwz 9,0x0(28); lwz 0,0x0(30); lwz 11,0x10(9); mr 5,9; mr 8,0; cmpw cr7,11,0; mfcr 11; rlwinm. 11,11,29,31,31; beq 13f; lwz 0,0x4(31); mr 9,3; cmpw 3,0; beq 8f; lwz 0,0x10(9); cmpw 8,0; bge 13f; 8:; lwz 0,0xc(5); cmpwi 0,0; bne 11f; 9:; mr 6,5; 10:; mr 4,31; mr 7,30; mr 3,29; li 5,0; mr 8,6; bl _s803A4E38_7; b 16f; 11:; mr 5,3; 12:; mr 4,31; mr 7,30; mr 3,29; mr 6,5; li 8,0; bl _s803A4E38_8; b 16f; 13:; cmpw 27,11; bne 14f; lwz 0,0x0(28); b 15f; 14:; mr 4,31; mr 5,30; addi 3,1,24; bl _s803A4E38_9; lwz 0,0x18(1); 15:; stw 0,0x0(29); 16:; mr 3,29; lwz 0,0x3c(1); mtspr 8,0; lmw 27,0x24(1); addi 1,1,56"
extern "C" void _s803A4E38_0();
extern "C" void _s803A4E38_1();
extern "C" void _s803A4E38_2();
extern "C" void _s803A4E38_3();
extern "C" void _s803A4E38_4();
extern "C" void _s803A4E38_5();
extern "C" void _s803A4E38_6();
extern "C" void _s803A4E38_7();
extern "C" void _s803A4E38_8();
extern "C" void _s803A4E38_9();
extern "C" void f_803A4E38() {}
