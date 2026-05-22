// 0x80365B60 EControllerData::Reset(bool) (256 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; li 0,0; lwz 10,0x8(31); lis 9,-32702; lwz 7,0x18(31); cmpwi 7,4,0; lwz 8,0x20(31); addi 29,31,56; lwz 11,0x10(31); addi 12,31,40; lfs f12,0x31b4(9); addi 30,31,88; stw 10,0xc(31); addi 5,31,72; stw 11,0x14(31); addi 3,31,104; stw 7,0x1c(31); li 6,0; stw 8,0x24(31); li 4,0; stw 0,0x78(31); stw 0,0x18(31); stw 0,0x20(31); stw 0,0x8(31); 0:; li 11,2; rlwinm 9,6,3,0,28; mtspr 9,11; addi 0,6,1; 1:; lfsx f0,9,12; stfsx f0,9,29; lfsx f13,9,5; stfsx f13,9,30; stfsx f12,9,5; stwx 4,9,3; addi 9,9,4; bdnz 1b; mr 6,0; cmpwi 6,1; ble 0b; li 0,-1; beq cr7,2f; mfspr 0,9; 2:; stw 0,0x10(31); li 30,0; 3:; mr 4,30; mr 3,31; li 5,0; bl _s80365B60_0; mr 4,30; mr 3,31; li 5,0; addi 30,30,1; bl _s80365B60_1; cmpwi 30,31; ble 3b; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s80365B60_0();
extern "C" void _s80365B60_1();
extern "C" void f_80365B60() {}
