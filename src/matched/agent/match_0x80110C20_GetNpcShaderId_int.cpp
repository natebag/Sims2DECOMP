// 0x80110C20 GetNpcShaderId(int, (96 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,4; lis 9,-32697; mr 4,3; addi 3,9,24012; bl _s80110C20_0; mr. 9,3; bne 0f; li 3,0; b 2f; 0:; cmpwi 31,0; beq 1f; lwz 3,0x8(9); cmpwi 3,0; bne 2f; 1:; lwz 3,0x4(9); 2:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s80110C20_0();
extern "C" void f_80110C20() {}
