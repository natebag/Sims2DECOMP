// 0x8016F10C CasSimRenderer::GetNumActiveBodyModels(void) (48 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 0,26; addi 3,3,112; mtspr 9,0; li 9,0; 0:; lwz 0,0x0(3); addi 3,3,4; cmpwi 0,0; beq 1f; addi 9,9,1; 1:; bdnz 0b; mr 3,9"
extern "C" int f_8016F10C() {}
