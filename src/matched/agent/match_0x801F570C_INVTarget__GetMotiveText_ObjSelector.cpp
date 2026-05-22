// 0x801F570C INVTarget::GetMotiveText(ObjSelector (404 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-112(1); mfspr 0,8; stmw 27,0x5c(1); stw 0,0x74(1); mr 29,3; mr 31,4; mr. 30,5; beq 7f; li 0,0; cmpwi 31,0; sth 0,0x0(30); li 3,0; beq 11f; mr 3,31; bl _s801F570C_0; mr. 3,3; bne 0f; mr 3,31; 0:; lwz 27,0x38(3); cmpwi 27,0; beq 7f; li 0,0; mr 3,29; mr 4,31; addi 5,1,72; addi 29,1,8; stw 0,0x4c(1); addi 6,1,76; stw 0,0x48(1); bl _s801F570C_1; li 31,0; mr 28,3; li 4,0; mr 3,29; li 5,64; crxor 6,6,6; bl _s801F570C_2; cmpwi 28,0; beq 1f; lwz 0,0x48(1); lis 9,-32705; addi 9,9,16952; lis 4,-32697; rlwinm 0,0,2,0,29; addi 4,4,24012; lwzx 5,9,0; addi 3,1,80; crxor 6,6,6; bl _s801F570C_3; lwz 3,0x4c(1); mr 4,29; lwz 31,0x50(1); bl _s801F570C_4; b 2f; 1:; stw 31,0x4c(1); 2:; lha 0,0x50(27); cmpwi 0,256; bne 5f; li 0,1; cmpwi 7,31,0; bne cr7,3f; li 0,0; 3:; cmpwi 0,0; beq 7f; li 4,0; beq cr7,4f; lwz 4,0x0(31); 4:; mr 3,30; bl _s801F570C_5; b 10f; 5:; cmpwi 28,0; beq 7f; lwz 0,0x4c(1); cmpwi 0,0; beq 7f; li 0,1; cmpwi 7,31,0; bne cr7,6f; li 0,0; 6:; cmpwi 0,0; bne 8f; 7:; li 3,0; b 11f; 8:; li 4,0; beq cr7,9f; lwz 4,0x0(31); 9:; mr 3,30; bl _s801F570C_6; lis 4,-32704; mr 3,30; addi 4,4,-23528; bl _s801F570C_7; mr 3,30; addi 4,1,8; bl _s801F570C_8; 10:; li 3,1; 11:; lwz 0,0x74(1); mtspr 8,0; lmw 27,0x5c(1); addi 1,1,112"
extern "C" void _s801F570C_0();
extern "C" void _s801F570C_1();
extern "C" void _s801F570C_2();
extern "C" void _s801F570C_3();
extern "C" void _s801F570C_4();
extern "C" void _s801F570C_5();
extern "C" void _s801F570C_6();
extern "C" void _s801F570C_7();
extern "C" void _s801F570C_8();
extern "C" void f_801F570C() {}
