// 0x801F5FC0 INVTarget::SetOnMsgInvShpSelectColor(char (212 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 30,0x28(1); stw 0,0x34(1); mr 31,3; mr 30,4; mr 3,30; bl _s801F5FC0_0; stb 3,0x3252(31); addi 5,1,24; lbz 4,0x3251(31); addi 6,1,32; mr 3,31; bl _s801F5FC0_1; mr 3,30; bl _s801F5FC0_2; lwz 0,0x20(1); stb 3,0x3252(31); cmpwi 0,11; bgt 0f; cmpwi 0,9; bge 3f; 0:; lwz 3,0x18(1); bl _s801F5FC0_3; addi 4,1,8; bl _s801F5FC0_4; cmpwi 3,0; beq 3f; lwz 0,0x84(31); addi 9,13,-28688; lwz 11,0x0(31); rlwinm 0,0,2,0,29; lbz 10,0x3252(31); lwzx 4,9,0; cmpwi 11,0; lwz 5,0x8(1); lwz 6,0xc(1); lwz 7,0x10(1); beq 1f; lwz 3,0x20(31); cmpwi 3,0; beq 1f; lwz 8,0x7c(31); mr 9,10; bl _s801F5FC0_5; b 2f; 1:; li 3,0; 2:; stw 3,0x3258(31); 3:; lwz 0,0x34(1); mtspr 8,0; lmw 30,0x28(1); addi 1,1,48"
extern "C" void _s801F5FC0_0();
extern "C" void _s801F5FC0_1();
extern "C" void _s801F5FC0_2();
extern "C" void _s801F5FC0_3();
extern "C" void _s801F5FC0_4();
extern "C" void _s801F5FC0_5();
extern "C" void f_801F5FC0() {}
