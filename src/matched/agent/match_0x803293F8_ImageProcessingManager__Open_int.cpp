// 0x803293F8 ImageProcessingManager::Open(int) (104 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; mulli 3,30,36; stw 30,-26584(13); bl _s803293F8_0; addi 11,30,-1; mr 9,3; cmpwi 30,0; beq 1f; li 10,-1; li 0,0; 0:; stw 10,0x0(9); cmpwi 11,0; stw 0,0x4(9); addi 11,11,-1; addi 9,9,36; bne 0b; 1:; stw 3,-26588(13); lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s803293F8_0();
extern "C" void f_803293F8() {}
