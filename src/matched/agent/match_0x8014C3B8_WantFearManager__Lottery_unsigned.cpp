// 0x8014C3B8 WantFearManager::Lottery(unsigned (140 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); li 11,0; mr 31,4; li 10,0; cmplw 11,5; bge 1f; mr 9,31; 0:; lwz 0,0x0(9); addi 10,10,1; addi 9,9,4; cmplw 10,5; add 11,11,0; blt 0b; 1:; cmpwi 11,0; li 3,-1; beq 4f; mr 3,11; bl _s8014C3B8_0; li 9,-1; mr. 3,3; blt 3f; addi 4,31,-4; 2:; lwzu 0,0x4(4); addi 9,9,1; subf. 3,0,3; bge 2b; 3:; mr 3,9; 4:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s8014C3B8_0();
extern "C" void f_8014C3B8() {}
