// 0x803C4F10 TArray<ENCamera, (152 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; mr 29,4; addi 9,5,-1; cmpwi 5,0; beq 2f; 0:; li 0,64; mr 8,30; mtspr 9,0; mr 10,29; addi 31,9,-1; addi 29,10,88; addi 30,8,88; mr 11,8; mr 9,10; 1:; lbz 0,0x0(9); addi 9,9,1; stb 0,0x0(11); addi 11,11,1; bdnz 1b; lwz 9,0x40(10); addi 3,8,72; addi 4,10,72; stw 9,0x40(8); lwz 0,0x44(10); stw 0,0x44(8); bl _s803C4F10_0; mr 9,31; cmpwi 9,-1; bne 0b; 2:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s803C4F10_0();
extern "C" void f_803C4F10() {}
