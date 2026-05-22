// 0x8034405C ENgcRenderer::ModelMatrices(EMat4 (80 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="rlwinm 0,5,3,3,28; stw 5,0x4570(3); addi 11,3,1904; mr. 4,4; beq 1f; cmpwi 11,0; beq 1f; cmpwi 0,0; beq 1f; mtspr 9,0; 0:; lwz 9,0x0(4); lwz 10,0x4(4); addi 4,4,8; stw 9,0x0(11); stw 10,0x4(11); addi 11,11,8; bdnz 0b; 1:; li 0,1; stw 0,0x510(3)"
extern "C" void f_8034405C() {}
