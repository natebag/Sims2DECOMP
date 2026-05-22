// 0x80361144 EStringRedBlackTreeNoCase::Find(char (180 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; mfcr 12; stmw 27,0xc(1); stw 0,0x24(1); stw 12,0x8(1); lwz 31,0x8(3); lis 9,-32700; addi 9,9,11816; mr 29,4; mr 28,5; cmpw 31,9; beq 5f; mr 27,9; cmpwi 4,28,0; 0:; addi 30,31,28; mr 4,29; mr 3,30; bl _s80361144_0; cmpwi 3,0; bne 2f; beq cr4,1f; lwz 0,0x18(31); stw 0,0x0(28); 1:; mr 3,31; b 6f; 2:; mr 3,30; mr 4,29; bl _s80361144_1; cmpwi 3,0; ble 3f; lwz 3,0x0(31); b 4f; 3:; lwz 3,0x4(31); 4:; mr 31,3; cmpw 31,27; bne 0b; 5:; li 3,0; 6:; lwz 0,0x24(1); lwz 12,0x8(1); mtspr 8,0; lmw 27,0xc(1); mtcrf 8,12; addi 1,1,32"
extern "C" void _s80361144_0();
extern "C" void _s80361144_1();
extern "C" void f_80361144() {}
