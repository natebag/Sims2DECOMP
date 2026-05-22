// 0x80328C50 EyeToyManager::Close(void) (132 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 0,-26604(13); cmpwi 0,0; beq 5f; lwz 0,-26620(13); li 9,0; lwz 3,-26608(13); cmplw 9,0; bge 1f; 0:; addi 9,9,1; cmplw 9,0; blt 0b; 1:; cmpwi 3,0; beq 4f; lwz 0,-8(3); add 9,3,0; cmpw 3,9; beq 3f; mr 0,3; 2:; addi 9,9,-1; cmpw 0,9; bne 2b; 3:; addi 3,3,-8; bl _s80328C50_0; 4:; li 0,0; stw 0,-26604(13); stw 0,-26608(13); 5:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s80328C50_0();
extern "C" void f_80328C50() {}
