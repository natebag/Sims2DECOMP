// 0x8033A430 ENgcRC::Texture(ETexture (80 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); mr. 4,4; beq 0f; lwz 0,0x20(4); lis 9,-28659; ori 9,9,48879; xor 0,0,9; subfic 9,0,0; adde 0,9,0; cmpwi 0,0; beq 1f; 0:; lis 3,-32691; addi 3,3,21688; bl _s8033A430_0; 1:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s8033A430_0();
extern "C" void f_8033A430() {}
