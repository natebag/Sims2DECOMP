// 0x80073090 SimModel::GetGameStateTextureID(unsigned (100 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lis 9,-32697; mr 11,3; lwz 0,0x6210(9); cmpwi 0,0; beq 0f; cmpwi 11,0; beq 2f; b 1f; 0:; cmpwi 11,0; beq 2f; cmpwi 4,0; bne 2f; 1:; lis 3,-32707; mr 4,11; addi 3,3,22036; bl _s80073090_0; b 3f; 2:; mr 3,11; 3:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s80073090_0();
extern "C" void f_80073090() {}
