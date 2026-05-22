// 0x802E1FD4 BackgroundImpl::Main(void) (220 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 29,0x14(1); stw 0,0x24(1); mr 30,3; addi 29,1,8; 0:; addi 3,30,872; mr 4,29; li 5,1; bl _s802E1FD4_0; cmpwi 3,0; beq 0b; lwz 31,0x8(1); lwz 0,0x0(31); cmpwi 0,2; beq 2f; bgt 1f; cmpwi 0,1; beq 3f; b 8f; 1:; cmpwi 0,3; beq 4f; cmpwi 0,4; beq 6f; b 8f; 2:; mr 3,31; bl _s802E1FD4_1; b 9f; 3:; lwz 3,0x4(31); bl _s802E1FD4_2; b 5f; 4:; lwz 0,0x4(31); cmpwi 0,0; beq 5f; mtspr 8,0; blrl; 5:; mr 3,31; bl _s802E1FD4_3; b 8f; 6:; lwz 0,0x4(31); cmpwi 0,0; beq 7f; lwz 3,0xc(31); mtspr 8,0; blrl; 7:; mr 3,31; bl _s802E1FD4_4; 8:; addi 3,30,8; bl _s802E1FD4_5; b 0b; 9:; lwz 0,0x24(1); mtspr 8,0; lmw 29,0x14(1); addi 1,1,32"
extern "C" void _s802E1FD4_0();
extern "C" void _s802E1FD4_1();
extern "C" void _s802E1FD4_2();
extern "C" void _s802E1FD4_3();
extern "C" void _s802E1FD4_4();
extern "C" void _s802E1FD4_5();
extern "C" void f_802E1FD4() {}
