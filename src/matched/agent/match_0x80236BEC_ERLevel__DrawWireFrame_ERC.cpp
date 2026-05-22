// 0x80236BEC ERLevel::DrawWireFrame(ERC (188 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); lwz 0,-26704(13); mr 30,4; addis 31,3,3; li 4,0; stw 0,-24004(31); li 5,0; stw 30,-24008(31); li 29,0; lwz 9,0x70(30); lwz 0,0x124(9); lha 3,0x120(9); mtspr 8,0; add 3,30,3; blrl; lwz 9,0x70(30); li 4,8; lwz 0,0x134(9); lha 3,0x130(9); mtspr 8,0; add 3,30,3; blrl; lwz 0,-7476(31); cmpw 29,0; bge 1f; addi 30,31,-15668; 0:; lwz 11,0x0(30); addi 29,29,1; lwz 4,-24008(31); addi 30,30,4; lwz 9,0x0(11); lwz 0,0x94(9); lha 3,0x90(9); mtspr 8,0; add 3,11,3; blrl; lwz 0,-7476(31); cmpw 29,0; blt 0b; 1:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void f_80236BEC() {}
