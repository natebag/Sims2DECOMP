// 0x8017A338 UIDBTarget::SetVariable(char (364 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-288(1); mfspr 0,8; stmw 28,0x110(1); stw 0,0x124(1); mr 29,4; mr 28,5; mr 3,29; bl _s8017A338_0; mr. 3,3; beq 7f; cmpwi 29,0; beq 7f; cmpwi 28,0; beq 7f; li 0,0; li 31,0; stb 0,0x88(1); li 10,0; stb 0,0x8(1); li 11,0; li 9,0; cmpw 31,3; addi 30,1,136; bge 4f; addi 8,1,8; li 6,0; mr 7,30; 0:; lbzx 0,29,9; cmpwi 0,58; bne 1f; addi 31,31,1; b 3f; 1:; cmpwi 31,1; bne 2f; stbx 0,8,10; addi 10,10,1; stbx 6,8,10; b 3f; 2:; cmpwi 31,2; bne 3f; stbx 0,7,11; addi 11,11,1; stbx 6,7,11; 3:; addi 9,9,1; cmpw 9,3; blt 0b; 4:; addi 3,1,8; bl _s8017A338_1; mr 3,30; bl _s8017A338_2; cmpwi 31,2; bne 7f; addi 3,1,8; bl _s8017A338_3; cmpwi 3,0; beq 7f; mr 3,30; bl _s8017A338_4; cmpwi 3,0; beq 7f; lbz 0,0x8(1); extsb 0,0; cmpwi 0,105; bne 5f; lis 4,-32706; mr 3,28; addi 4,4,11364; addi 5,1,264; crxor 6,6,6; bl _s8017A338_5; lwz 4,0x108(1); mr 3,30; bl _s8017A338_6; b 7f; 5:; cmpwi 0,102; bne 6f; mr 3,28; bl _s8017A338_7; mr 3,30; bl _s8017A338_8; b 7f; 6:; cmpwi 0,115; bne 7f; mr 3,30; mr 4,28; bl _s8017A338_9; 7:; lwz 0,0x124(1); mtspr 8,0; lmw 28,0x110(1); addi 1,1,288"
extern "C" void _s8017A338_0();
extern "C" void _s8017A338_1();
extern "C" void _s8017A338_2();
extern "C" void _s8017A338_3();
extern "C" void _s8017A338_4();
extern "C" void _s8017A338_5();
extern "C" void _s8017A338_6();
extern "C" void _s8017A338_7();
extern "C" void _s8017A338_8();
extern "C" void _s8017A338_9();
extern "C" void f_8017A338() {}
