// 0x801F5010 INVTarget::SetOnMsgInvShpPrepareObjectInfo(char (228 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 30,0x18(1); stw 0,0x24(1); mr 30,3; li 0,0; addi 31,1,8; lbz 4,0x3251(30); stw 0,0x88(30); mr 5,31; addi 6,1,16; bl _s801F5010_0; lwz 0,0x10(1); cmpwi 0,9; beq 0f; blt 3f; cmpwi 0,10; beq 1f; cmpwi 0,11; beq 2f; b 3f; 0:; mr 4,31; mr 3,30; li 5,0; li 6,1; bl _s801F5010_1; b 4f; 1:; mr 4,31; mr 3,30; li 5,0; li 6,1; bl _s801F5010_2; b 4f; 2:; mr 4,31; mr 3,30; li 5,0; li 6,1; bl _s801F5010_3; b 4f; 3:; lwz 0,0x10(1); cmplwi 0,14; bgt 5f; lwz 4,0x8(1); mr 3,30; lbz 7,0x3252(30); li 5,0; li 6,1; bl _s801F5010_4; 4:; cmpwi 3,0; beq 5f; li 0,1; stw 0,0x88(30); 5:; lwz 0,0x24(1); mtspr 8,0; lmw 30,0x18(1); addi 1,1,32"
extern "C" void _s801F5010_0();
extern "C" void _s801F5010_1();
extern "C" void _s801F5010_2();
extern "C" void _s801F5010_3();
extern "C" void _s801F5010_4();
extern "C" void f_801F5010() {}
