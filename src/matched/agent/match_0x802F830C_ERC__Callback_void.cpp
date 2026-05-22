// 0x802F830C ERC::Callback(void (200 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 26,0x8(1); stw 0,0x24(1); mr 30,3; mr 26,4; lwz 9,0x70(30); mr 27,5; li 5,0; li 4,0; lwz 0,0x2b4(9); mr 28,6; lha 3,0x2b0(9); mr 29,7; mtspr 8,0; add 3,30,3; blrl; lwz 9,0x70(30); li 4,1; lwz 0,0x2ac(9); lha 3,0x2a8(9); mtspr 8,0; add 3,30,3; blrl; li 0,30; stb 29,0x1(3); stb 0,0x0(3); li 4,1; stw 27,0x4(3); sth 28,0x2(3); lwz 9,0x70(30); lwz 0,0x2ac(9); lha 3,0x2a8(9); mtspr 8,0; add 3,30,3; blrl; li 0,31; stw 26,0x4(3); stb 0,0x0(3); lwz 9,0x70(30); lha 3,0x2b8(9); lwz 0,0x2bc(9); add 3,30,3; mtspr 8,0; blrl; lwz 0,0x24(1); mtspr 8,0; lmw 26,0x8(1); addi 1,1,32"
extern "C" void f_802F830C() {}
