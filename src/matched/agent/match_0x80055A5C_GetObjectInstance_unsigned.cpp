// 0x80055A5C GetObjectInstance(unsigned (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 0,0x14(1); lis 9,-32697; mr 4,3; lwz 3,0x5e94(9); cmpwi 3,0; beq 0f; lwz 3,0x4(3); cmpwi 3,0; bne 1f; 0:; li 3,0; b 2f; 1:; li 0,0; addi 3,3,4; stw 0,0x8(1); addi 5,1,8; bl _s80055A5C_0; cmpwi 3,0; li 3,0; beq 2f; lwz 0,0x8(1); cmpwi 0,0; beq 2f; mr 3,0; 2:; lwz 0,0x14(1); mtspr 8,0; addi 1,1,16"
extern "C" void _s80055A5C_0();
extern "C" void f_80055A5C() {}
