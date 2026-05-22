// 0x802939E8 AptCIH::AptCIH(AptVirtualFunctionTable_Indices, (288 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; mr 30,5; mr 29,6; li 5,0; bl _s802939E8_0; lis 9,-32704; addi 3,31,12; addi 9,9,23568; stw 9,0x8(31); bl _s802939E8_1; lis 11,-32704; lis 9,-32704; lfs f0,0x5c9c(9); cmpwi 29,0; lfs f13,0x5c98(11); stw 30,0x4c(31); stfs f13,0x34(31); stfs f0,0x44(31); stfs f13,0x10(31); stfs f0,0x14(31); stfs f0,0x18(31); stfs f13,0x1c(31); stfs f0,0x20(31); stfs f0,0x24(31); stfs f13,0x28(31); stfs f13,0x2c(31); stfs f13,0x30(31); stfs f0,0x38(31); stfs f0,0x3c(31); stfs f0,0x40(31); stw 29,0x48(31); beq 0f; lwz 9,0x8(29); lis 4,-32704; lis 5,-32704; addi 4,4,22276; lha 3,0x8(9); addi 5,5,22360; lwz 0,0xc(9); li 6,99; add 3,29,3; mtspr 8,0; blrl; 0:; lwz 0,0x5c(31); li 30,0; mr 3,31; li 4,1; rlwinm 0,0,0,20,15; stw 0,0x5c(31); sth 30,0x5c(31); bl _s802939E8_2; lwz 11,0x5c(31); mr 3,31; lwz 0,0x58(31); lwz 9,0x0(31); ori 11,11,2048; ori 0,0,32766; rlwinm 11,11,0,22,20; rlwimi 9,30,26,5,5; stw 0,0x58(31); stw 9,0x0(31); stw 30,0x60(31); stw 11,0x5c(31); lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s802939E8_0();
extern "C" void _s802939E8_1();
extern "C" void _s802939E8_2();
extern "C" void f_802939E8() {}
