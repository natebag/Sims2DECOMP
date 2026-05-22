// 0x800491CC InfluenceMap::RemoveObjectEntry(cXObject (200 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 27,0x1c(1); stw 0,0x34(1); mr 29,3; mr 27,4; addi 6,1,8; bl _s800491CC_0; lwz 3,0x14(1); cmpwi 3,0; bge 0f; addi 3,3,15; 0:; srawi 30,3,4; b 6f; 1:; lwz 9,0x10(1); cmpwi 9,0; bge 2f; addi 9,9,15; 2:; srawi 31,9,4; addi 28,30,1; b 4f; 3:; lwz 3,0x4(29); lwz 0,0x8(29); mullw 3,30,3; add 3,3,31; rlwinm 3,3,4,0,27; addi 31,31,1; add 3,0,3; bl _s800491CC_1; 4:; lwz 9,0x8(1); mr 4,27; addic. 0,9,-1; bge 5f; addi 0,9,14; 5:; srawi 0,0,4; cmpw 31,0; ble 3b; mr 30,28; 6:; lwz 9,0xc(1); addic. 0,9,-1; bge 7f; addi 0,9,14; 7:; srawi 0,0,4; cmpw 30,0; ble 1b; lwz 0,0x34(1); mtspr 8,0; lmw 27,0x1c(1); addi 1,1,48"
extern "C" void _s800491CC_0();
extern "C" void _s800491CC_1();
extern "C" void f_800491CC() {}
