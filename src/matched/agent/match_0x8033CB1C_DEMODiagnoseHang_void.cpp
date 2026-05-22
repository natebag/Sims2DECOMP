// 0x8033CB1C __DEMODiagnoseHang(void) (440 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-64(1); mfspr 0,8; stmw 28,0x30(1); stw 0,0x44(1); addi 3,1,12; addi 4,1,16; addi 5,1,20; addi 6,1,24; bl _s8033CB1C_0; li 30,1; addi 3,1,28; addi 4,1,32; addi 5,1,36; addi 6,1,40; bl _s8033CB1C_1; lwz 0,0x10(1); lwz 11,0x20(1); lwz 10,0x1c(1); xor 29,11,0; subfic 9,29,0; adde 29,9,29; lwz 9,0xc(1); lwz 11,0x28(1); xor 31,10,9; subfic 0,31,0; adde 31,0,31; lwz 0,0x18(1); cmpw 11,0; bne 0f; li 30,0; 0:; lwz 9,0x24(1); li 28,1; lwz 0,0x14(1); cmpw 9,0; bne 1f; li 28,0; 1:; addi 3,1,8; addi 5,1,9; mr 4,3; mr 7,3; addi 6,1,10; bl _s8033CB1C_2; lis 3,-32702; lbz 4,0x9(1); lbz 5,0xa(1); addi 3,3,7180; mr 6,29; mr 7,31; mr 8,30; mr 9,28; crxor 6,6,6; bl _s8033CB1C_3; cmpwi 6,31,0; bne cr6,2f; cmpwi 30,0; beq 2f; lis 3,-32702; addi 3,3,7208; crxor 6,6,6; bl _s8033CB1C_4; b 6f; 2:; cmpwi 7,29,0; bne cr7,3f; beq cr6,3f; cmpwi 30,0; beq 3f; lis 3,-32702; addi 3,3,7240; crxor 6,6,6; bl _s8033CB1C_5; b 6f; 3:; lbz 0,0xa(1); mr 9,0; cmpwi 0,0; bne 4f; beq cr7,4f; beq cr6,4f; cmpwi 30,0; beq 4f; lis 3,-32702; addi 3,3,7280; crxor 6,6,6; bl _s8033CB1C_6; b 6f; 4:; lbz 0,0x9(1); cmpwi 0,0; beq 5f; rlwinm 0,9,0,24,31; cmpwi 0,0; beq 5f; beq cr7,5f; beq cr6,5f; cmpwi 30,0; beq 5f; cmpwi 28,0; beq 5f; lis 3,-32702; addi 3,3,7320; crxor 6,6,6; bl _s8033CB1C_7; b 6f; 5:; lis 3,-32702; addi 3,3,7368; crxor 6,6,6; bl _s8033CB1C_8; 6:; lwz 0,0x44(1); mtspr 8,0; lmw 28,0x30(1); addi 1,1,64"
extern "C" void _s8033CB1C_0();
extern "C" void _s8033CB1C_1();
extern "C" void _s8033CB1C_2();
extern "C" void _s8033CB1C_3();
extern "C" void _s8033CB1C_4();
extern "C" void _s8033CB1C_5();
extern "C" void _s8033CB1C_6();
extern "C" void _s8033CB1C_7();
extern "C" void _s8033CB1C_8();
extern "C" void f_8033CB1C() {}
