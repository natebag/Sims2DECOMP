// 0x802F9080 ERC::Vertex(int, (208 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 24,0x8(1); stw 0,0x2c(1); mr 31,3; mr 29,5; mr 28,6; mr 27,7; mr 26,8; mr 25,9; mr 24,10; mr. 30,4; beq 0f; lwz 9,0x70(31); li 4,2; li 5,0; lwz 0,0x2b4(9); lha 3,0x2b0(9); mtspr 8,0; add 3,31,3; blrl; lwz 11,0x0(31); li 4,4; lwz 0,0x54(11); add 0,0,30; stw 0,0x54(11); lwz 9,0x70(31); lwz 0,0x2ac(9); lha 3,0x2a8(9); mtspr 8,0; add 3,31,3; blrl; li 0,46; stw 29,0x1c(3); stb 0,0x0(3); stw 30,0x4(3); stw 28,0x8(3); stw 27,0xc(3); stw 26,0x10(3); stw 25,0x14(3); stw 24,0x18(3); lwz 9,0x70(31); lha 3,0x2b8(9); lwz 0,0x2bc(9); add 3,31,3; mtspr 8,0; blrl; 0:; lwz 0,0x2c(1); mtspr 8,0; lmw 24,0x8(1); addi 1,1,40"
extern "C" void f_802F9080() {}
