// 0x8032FCA4 ENgcGraphics::DrawCensorRects(ERC (164 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 27,0x1c(1); stw 0,0x34(1); mr 28,3; li 29,0; lwz 0,0x2a4(28); mr 27,4; cmpw 29,0; bge 1f; addi 30,1,8; addi 31,28,428; 0:; lfs f0,-200(31); mr 4,30; lfs f12,-196(31); addi 5,1,16; stfs f0,0x8(1); addi 29,29,1; lfs f0,-8(31); lfs f13,-4(31); stfs f12,0x4(30); stfs f0,0x10(1); stfs f13,0x14(1); lwz 9,0x70(27); lfs f1,0x0(31); lwz 0,0x344(9); addi 31,31,12; lha 3,0x340(9); mtspr 8,0; add 3,27,3; blrl; lwz 0,0x2a4(28); cmpw 29,0; blt 0b; 1:; li 0,0; stw 0,0x2a4(28); lwz 0,0x34(1); mtspr 8,0; lmw 27,0x1c(1); addi 1,1,48"
extern "C" void f_8032FCA4() {}
