// 0x80364FC4 ETexture::~ETexture(void) (80 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lis 0,-8531; mr 11,3; ori 0,0,48879; lis 9,-32697; addi 9,9,-9440; stw 0,0x20(11); stw 9,0x24(11); andi. 0,4,1; beq 0f; lis 3,-32692; mr 4,11; addi 3,3,-7364; bl _s80364FC4_0; 0:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s80364FC4_0();
extern "C" void f_80364FC4() {}
