// 0x80239E28 EmitterGeomdPreProcessCB(void (232 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-312(1); mfspr 0,8; stmw 29,0x12c(1); stw 0,0x13c(1); lwz 9,-26512(13); lwz 3,0x30(9); cmpwi 3,0; beq 2f; addi 30,1,8; addi 29,1,32; mr 5,30; mr 4,29; bl _s80239E28_0; li 0,4; addi 10,1,64; mtspr 9,0; addi 3,1,76; addi 5,1,20; addi 6,1,48; 0:; bdnz 0b; li 0,4; lwz 11,0x8(1); mtspr 9,0; 1:; bdnz 1b; lwz 9,0x8(30); li 7,1; lwz 0,0x4(30); li 8,0; stw 11,0x40(1); mr 4,6; stw 9,0x8(10); stw 0,0x4(10); lwz 10,-28384(13); lwz 0,0x14(1); lwz 9,0x8(5); lwz 11,0x4(5); stw 0,0x4c(1); stw 9,0x8(3); stw 11,0x4(3); lwz 9,0x20(1); lwz 0,0x4(29); lwz 11,0x8(29); stw 9,0x30(1); stw 0,0x4(6); stw 11,0x8(6); stw 7,0x120(1); stw 8,0x124(1); lwz 9,0x70(10); lha 3,0x168(9); lwz 0,0x16c(9); add 3,10,3; mtspr 8,0; blrl; 2:; lwz 0,0x13c(1); mtspr 8,0; lmw 29,0x12c(1); addi 1,1,312"
extern "C" void _s80239E28_0();
extern "C" void f_80239E28() {}
