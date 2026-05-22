// 0x80287844 AptArray::sMethod_sortOn(AptValue (212 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; li 11,0; lwz 9,0x0(31); rlwinm 0,9,0,25,31; cmpwi 0,22; bne 0f; rlwinm 11,9,5,31,31; 0:; cmpwi 11,0; beq 2f; cmpwi 4,0; ble 2f; lis 9,-32694; addi 4,13,-22980; lwz 11,-16032(9); addi 9,9,-16032; lwz 0,0x8(9); rlwinm 11,11,2,0,29; add 11,11,0; lwz 3,-4(11); bl _s80287844_0; lwz 4,0x2c(31); lis 6,-32728; lwz 3,0x24(31); addi 6,6,30452; li 5,4; bl _s80287844_1; lwz 4,-22980(13); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 1f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s80287844_2; 1:; lis 9,-32700; lhz 11,-6476(9); addi 0,9,-6476; stw 0,-22980(13); addi 11,11,1; sth 11,-6476(9); 2:; lwz 3,-22936(13); lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s80287844_0();
extern "C" void _s80287844_1();
extern "C" void _s80287844_2();
extern "C" void f_80287844() {}
