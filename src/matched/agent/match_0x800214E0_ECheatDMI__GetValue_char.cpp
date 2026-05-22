// 0x800214E0 ECheatDMI::GetValue(char (288 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 9,0xc(3); mr 3,4; lwz 0,0x4c(9); cmpwi 0,4; beq 4f; bgt 0f; cmpwi 0,2; beq 1f; cmpwi 0,3; beq 3f; b 7f; 0:; cmpwi 0,5; beq 5f; cmpwi 0,7; beq 6f; b 7f; 1:; lwz 9,0x50(9); lwz 0,0x0(9); cmpwi 0,0; beq 2f; lis 9,-32707; addi 11,9,884; lwz 0,0x374(9); lbz 10,0x4(11); stw 0,0x0(3); stb 10,0x4(3); b 8f; 2:; lis 9,-32707; addi 11,9,892; lwz 0,0x37c(9); lhz 10,0x4(11); stw 0,0x0(3); sth 10,0x4(3); b 8f; 3:; lwz 9,0x50(9); lis 4,-32707; addi 4,4,900; lbz 5,0x0(9); crxor 6,6,6; bl _s800214E0_0; b 8f; 4:; lwz 9,0x50(9); lis 4,-32707; addi 4,4,900; lbz 5,0x0(9); extsb 5,5; crxor 6,6,6; bl _s800214E0_1; b 8f; 5:; lwz 9,0x50(9); lis 4,-32707; addi 4,4,900; lha 5,0x0(9); crxor 6,6,6; bl _s800214E0_2; b 8f; 6:; lwz 9,0x50(9); lis 4,-32707; addi 4,4,840; lfs f1,0x0(9); creqv 6,6,6; bl _s800214E0_3; b 8f; 7:; li 0,0; stb 0,0x0(3); 8:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s800214E0_0();
extern "C" void _s800214E0_1();
extern "C" void _s800214E0_2();
extern "C" void _s800214E0_3();
extern "C" void f_800214E0() {}
