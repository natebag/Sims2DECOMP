// 0x800D146C NeighborhoodImpl::NotifyAllResidents(WantFear::Notification (324 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stmw 22,0x10(1); stw 0,0x3c(1); lwz 11,-21424(13); mr 30,3; mr 22,4; mr 23,5; lwz 9,0x0(11); li 25,0; lwz 0,0x3c(9); lha 3,0x38(9); mtspr 8,0; add 3,11,3; blrl; lwz 9,0x0(30); mr 26,3; lis 11,-32697; lwz 0,0x124(9); lha 3,0x120(9); mtspr 8,0; lwz 4,0x5c5c(11); add 3,30,3; blrl; addi 9,30,116; lwz 28,0x74(30); lwz 0,0x4(9); mr 27,3; cmpw 28,0; beq 4f; mr 24,9; 0:; lwz 31,0x0(28); cmpw 31,23; beq 3f; lwz 30,0x0(26); mr 3,31; lha 29,0x58(30); addi 30,30,88; add 29,26,29; bl _s800D146C_0; lwz 0,0x4(30); mr 4,3; mr 3,29; mtspr 8,0; blrl; cmpwi 3,0; bne 1f; lwz 30,0x0(27); mr 3,31; lha 29,0x58(30); addi 30,30,88; add 29,27,29; bl _s800D146C_1; lwz 0,0x4(30); mr 4,3; mr 3,29; mtspr 8,0; blrl; cmpwi 3,0; beq 3f; 1:; mr 3,31; mr 4,22; li 5,1; bl _s800D146C_2; mr 0,3; mr 3,25; cmpw 3,0; bge 2f; mr 3,0; 2:; stw 3,0x8(1); mr 25,3; 3:; lwz 0,0x4(24); addi 28,28,4; cmpw 28,0; bne 0b; 4:; mr 3,25; lwz 0,0x3c(1); mtspr 8,0; lmw 22,0x10(1); addi 1,1,56"
extern "C" void _s800D146C_0();
extern "C" void _s800D146C_1();
extern "C" void _s800D146C_2();
extern "C" void f_800D146C() {}
