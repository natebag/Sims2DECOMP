// 0x80307714 ETweak::Read(void) (304 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; lwz 9,0x20(30); addi 29,30,28; lbz 0,0x0(9); cmpwi 0,0; bne 0f; lwz 4,0x18(30); mr 3,29; bl _s80307714_0; cmpwi 3,0; beq 9f; 0:; lwz 31,0xc(30); cmpwi 31,0; beq 8f; 1:; lwz 30,0x0(31); lwz 0,0x8(30); cmpwi 0,1; beq 4f; bgt 2f; cmpwi 0,0; beq 3f; b 7f; 2:; cmpwi 0,2; beq 5f; cmpwi 0,3; beq 6f; b 7f; 3:; lwz 9,0x0(30); mr 3,29; lwz 4,0x4(30); lbz 5,0x0(9); bl _s80307714_1; lwz 9,0x0(30); stb 3,0x0(9); b 7f; 4:; lwz 9,0x0(30); mr 3,29; lwz 4,0x4(30); lwz 5,0x0(9); bl _s80307714_2; lwz 9,0x0(30); stw 3,0x0(9); b 7f; 5:; lwz 9,0x0(30); mr 3,29; lwz 4,0x4(30); lfs f1,0x0(9); bl _s80307714_3; lwz 9,0x0(30); stfs f1,0x0(9); b 7f; 6:; lwz 4,0x4(30); mr 3,29; lwz 30,0x0(30); li 5,0; bl _s80307714_4; mr 4,3; mr 3,30; bl _s80307714_5; 7:; lwz 31,0x8(31); cmpwi 31,0; bne 1b; 8:; mr 3,29; li 4,0; li 5,0; li 6,0; bl _s80307714_6; 9:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s80307714_0();
extern "C" void _s80307714_1();
extern "C" void _s80307714_2();
extern "C" void _s80307714_3();
extern "C" void _s80307714_4();
extern "C" void _s80307714_5();
extern "C" void _s80307714_6();
extern "C" void f_80307714() {}
