// 0x8006D3CC ESims3DHead::ResetShaders(void) (76 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 3,-32260(13); cmpwi 3,0; beq 0f; bl _s8006D3CC_0; li 0,0; stw 0,-32260(13); 0:; lwz 3,-32256(13); cmpwi 3,0; beq 1f; bl _s8006D3CC_1; li 0,0; stw 0,-32256(13); 1:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s8006D3CC_0();
extern "C" void _s8006D3CC_1();
extern "C" void f_8006D3CC() {}
