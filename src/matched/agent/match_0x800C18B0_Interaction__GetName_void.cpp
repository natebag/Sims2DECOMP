// 0x800C18B0 Interaction::GetName(void) (176 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; addi 29,30,52; mr 3,29; bl _s800C18B0_0; cmpwi 3,0; bne 1f; mr 3,30; bl _s800C18B0_1; mr. 31,3; beq 1f; lwz 9,0x0(31); lha 3,0xc8(9); lwz 0,0xcc(9); add 3,31,3; mtspr 8,0; blrl; cmpwi 3,0; beq 0f; lis 4,-32706; mr 3,29; addi 4,4,-24748; bl _s800C18B0_2; 0:; lwz 9,0x0(31); lha 3,0x1a0(9); lwz 0,0x1a4(9); add 3,31,3; mtspr 8,0; blrl; mr 4,3; mr 3,29; bl _s800C18B0_3; 1:; lwz 0,0x3c(30); addi 3,30,52; rlwinm 0,0,0,25,23; stw 0,0x3c(30); lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s800C18B0_0();
extern "C" void _s800C18B0_1();
extern "C" void _s800C18B0_2();
extern "C" void _s800C18B0_3();
extern "C" void f_800C18B0() {}
