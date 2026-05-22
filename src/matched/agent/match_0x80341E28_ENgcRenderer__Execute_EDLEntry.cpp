// 0x80341E28 ENgcRenderer::Execute(EDLEntry (192 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 31,3; li 0,0; lis 9,-32700; stw 4,0x4dc(31); addi 28,9,11088; stw 0,0x4e0(31); addi 27,28,4; 0:; lwz 9,0x4dc(31); lbz 11,0x0(9); mr 4,9; addi 9,9,8; stw 9,0x4dc(31); rlwinm 10,11,3,0,28; add 9,10,28; mr 11,10; lha 0,0x2(9); cmpwi 7,0,0; rlwinm 8,0,3,0,28; mcrf cr0,cr7; blt 1f; lha 0,0x4(9); lwzx 9,31,0; add 9,8,9; lwz 29,-8(9); lwz 30,-4(9); mr 9,30; b 2f; 1:; lwzx 9,27,10; 2:; lhax 11,28,11; srawi 0,29,16; add 0,0,11; bge cr7,3f; mr 0,11; 3:; add 3,31,0; mtspr 8,9; blrl; lwz 0,0x4e0(31); cmpwi 0,0; beq 0b; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void f_80341E28() {}
