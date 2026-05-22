// 0x800AF4B4 cBoxX::SetAmbientScore(int) (264 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stw 31,0x2c(1); stw 0,0x34(1); mr 31,3; lwz 0,0x30(31); cmpw 4,0; beq 8f; cmpwi 0,4; beq 5f; bgt 0f; cmpwi 0,1; beq 1f; b 7f; 0:; cmpwi 0,5; beq 3f; b 7f; 1:; cmpwi 4,5; beq 6f; lis 9,-32697; lwz 9,0x5e94(9); cmpwi 9,0; beq 8f; lwz 0,0x64(31); cmpwi 0,0; beq 8f; lwz 5,0x54(9); lis 4,-32706; addi 3,1,8; addi 4,4,-26868; crxor 6,6,6; bl _s800AF4B4_0; lwz 3,0x64(31); addi 4,1,8; bl _s800AF4B4_1; lwz 3,0x64(31); bl _s800AF4B4_2; lwz 0,0x74(31); li 4,1; lwz 3,0x64(31); cmpwi 0,0; bne 2f; li 4,0; 2:; bl _s800AF4B4_3; b 8f; 3:; cmpwi 4,1; beq 4f; cmpwi 4,4; bne 8f; 4:; mr 3,31; bl _s800AF4B4_4; b 8f; 5:; cmpwi 4,5; bne 8f; 6:; mr 3,31; bl _s800AF4B4_5; b 8f; 7:; lwz 3,0x64(31); cmpwi 3,0; beq 8f; bl _s800AF4B4_6; 8:; lwz 0,0x34(1); mtspr 8,0; lwz 31,0x2c(1); addi 1,1,48"
extern "C" void _s800AF4B4_0();
extern "C" void _s800AF4B4_1();
extern "C" void _s800AF4B4_2();
extern "C" void _s800AF4B4_3();
extern "C" void _s800AF4B4_4();
extern "C" void _s800AF4B4_5();
extern "C" void _s800AF4B4_6();
extern "C" void f_800AF4B4() {}
