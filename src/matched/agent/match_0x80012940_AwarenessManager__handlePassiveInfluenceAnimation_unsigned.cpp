// 0x80012940 AwarenessManager::handlePassiveInfluenceAnimation(unsigned (308 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lwz 0,0x0(31); andi. 9,0,256; beq 7f; cmplwi 4,9; bgt 0f; cmplwi 4,7; bge 2f; cmplwi 4,4; bgt 6f; cmplwi 4,1; bge 4f; b 2f; 0:; cmplwi 4,15; bgt 1f; cmplwi 4,12; bge 4f; cmpwi 4,10; beq 6f; b 7f; 1:; cmpwi 4,16; beq 6f; cmpwi 4,17; beq 4f; b 7f; 2:; lwz 11,0x34(31); li 4,2; lwz 10,0x0(11); lwz 9,0x4(10); lha 3,0x260(9); lwz 0,0x264(9); add 3,10,3; mtspr 8,0; blrl; cmpwi 3,0; bne 3f; lwz 3,0x8(31); li 4,512; li 5,0; b 5f; 3:; lwz 3,0x34(31); lwz 9,0x4(3); lha 0,0x168(9); lwz 9,0x16c(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; beq 4f; mr 3,31; bl _s80012940_0; b 7f; 4:; lwz 3,0x8(31); lis 5,-32688; li 4,512; addi 5,5,-20000; 5:; bl _s80012940_1; lis 9,-32707; lis 11,-32707; lwz 3,0x8(31); li 4,512; lfs f1,-9020(9); lfs f3,-9016(11); lfs f2,-32300(13); bl _s80012940_2; b 7f; 6:; mr 3,31; bl _s80012940_3; 7:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s80012940_0();
extern "C" void _s80012940_1();
extern "C" void _s80012940_2();
extern "C" void _s80012940_3();
extern "C" void f_80012940() {}
