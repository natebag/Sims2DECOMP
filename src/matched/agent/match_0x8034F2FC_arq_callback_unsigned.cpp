// 0x8034F2FC arq_callback(unsigned (320 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 26,0x8(1); stw 0,0x24(1); lis 27,-32690; li 29,4; addi 28,27,-14064; li 26,5; li 31,0; mr 11,28; 0:; cmpw 11,3; bne 9f; addi 30,28,8; lwzx 9,30,31; cmpwi 9,0; beq 3f; lwz 0,0x0(9); cmpwi 0,4; beq 1f; stwx 29,31,28; b 10f; 1:; lwz 0,0x74(11); andis. 11,0,64; bne 2f; lwz 3,0x1c(9); li 4,1; bl _s8034F2FC_0; 2:; lwzx 9,30,31; stw 26,0x0(9); 3:; addi 9,27,-14064; addi 30,9,12; lwzx 11,30,31; cmpwi 11,0; beq 6f; lwz 0,0x0(11); cmpwi 0,4; beq 4f; stwx 29,9,31; b 10f; 4:; add 9,31,9; lwz 0,0x74(9); andis. 9,0,64; bne 5f; lwz 3,0x1c(11); li 4,1; bl _s8034F2FC_1; 5:; lwzx 9,30,31; stw 26,0x0(9); 6:; addi 9,27,-14064; addi 29,9,28; lwzx 3,29,31; cmpwi 3,0; beq 8f; add 30,31,9; lwz 0,0x74(30); andis. 9,0,64; bne 7f; li 4,1; bl _s8034F2FC_2; 7:; lbz 3,0x14(30); lwzx 30,29,31; bl _s8034F2FC_3; mr 4,3; mr 3,30; bl _s8034F2FC_4; lwzx 3,29,31; li 4,0; bl _s8034F2FC_5; 8:; stwx 26,31,28; b 10f; 9:; addi 11,11,120; addi 0,28,120; cmplw 11,0; addi 31,31,120; ble 0b; 10:; lwz 0,0x24(1); mtspr 8,0; lmw 26,0x8(1); addi 1,1,32"
extern "C" void _s8034F2FC_0();
extern "C" void _s8034F2FC_1();
extern "C" void _s8034F2FC_2();
extern "C" void _s8034F2FC_3();
extern "C" void _s8034F2FC_4();
extern "C" void _s8034F2FC_5();
extern "C" void f_8034F2FC() {}
