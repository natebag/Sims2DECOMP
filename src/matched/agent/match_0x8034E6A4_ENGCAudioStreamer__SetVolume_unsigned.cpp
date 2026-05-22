// 0x8034E6A4 ENGCAudioStreamer::SetVolume(unsigned (304 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,4; mr 31,5; bl _s8034E6A4_0; mr 3,30; bl _s8034E6A4_1; mulli 11,3,120; lis 9,-32690; addi 8,9,-14064; lwzx 0,8,11; xori 7,0,2; subfic 9,7,0; adde 7,9,7; xori 10,0,5; subfic 9,10,0; adde. 10,9,10; beq 1f; addi 9,8,8; lwzx 9,9,11; cmpwi 9,0; beq 0f; lwz 0,0x0(9); xori 10,0,5; subfic 9,10,0; adde 10,9,10; 0:; cmpwi 10,0; beq 1f; addi 9,8,12; lwzx 9,9,11; cmpwi 9,0; beq 1f; lwz 0,0x0(9); xori 10,0,5; subfic 8,10,0; adde 10,8,10; 1:; cmpwi 7,3,-1; beq cr7,3f; cmpwi 7,0; beq 2f; mulli 0,3,120; lis 9,-32690; addi 9,9,-14064; add 9,0,9; lwz 11,0x74(9); andis. 0,11,32; bne 2f; stb 31,0x14(9); 2:; beq cr7,3f; cmpwi 10,0; beq 3f; mulli 10,3,120; lis 9,-32690; addi 9,9,-14064; add 11,10,9; lwz 0,0x74(11); andis. 8,0,32; bne 3f; stb 31,0x14(11); addi 9,9,28; mr 3,31; lwzx 30,9,10; cmpwi 30,0; beq 3f; bl _s8034E6A4_2; mr 4,3; mr 3,30; bl _s8034E6A4_3; 3:; bl _s8034E6A4_4; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8034E6A4_0();
extern "C" void _s8034E6A4_1();
extern "C" void _s8034E6A4_2();
extern "C" void _s8034E6A4_3();
extern "C" void _s8034E6A4_4();
extern "C" void f_8034E6A4() {}
