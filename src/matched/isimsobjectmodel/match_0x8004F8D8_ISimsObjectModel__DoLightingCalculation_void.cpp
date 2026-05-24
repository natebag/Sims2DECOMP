// 0x8004F8D8 ISimsObjectModel::DoLightingCalculation(void) (712 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 28,0x10(1); stw 0,0x24(1); mr 31,3; lwz 0,0x32c(31); andi. 9,0,4; beq 2f; lis 9,-32696; addi 11,31,296; addi 9,9,21564; li 10,240; 0:; lwz 0,0x0(9); addic. 10,10,-24; stw 0,0x0(11); lwz 0,0x4(9); stw 0,0x4(11); lwz 0,0x8(9); stw 0,0x8(11); lwz 0,0xc(9); stw 0,0xc(11); lwz 0,0x10(9); stw 0,0x10(11); lwz 0,0x14(9); addi 9,9,24; stw 0,0x14(11); addi 11,11,24; bne 0b; lwz 0,0x0(9); stw 0,0x0(11); lwz 0,0x4(9); stw 0,0x4(11); lwz 0,0x8(31); cmpwi 0,0; beq 10f; lis 9,-32696; addi 3,31,544; addi 9,9,21564; li 11,240; 1:; lwz 0,0x0(9); addic. 11,11,-24; stw 0,0x0(3); lwz 0,0x4(9); stw 0,0x4(3); lwz 0,0x8(9); stw 0,0x8(3); lwz 0,0xc(9); stw 0,0xc(3); lwz 0,0x10(9); stw 0,0x10(3); lwz 0,0x14(9); addi 9,9,24; stw 0,0x14(3); addi 3,3,24; bne 1b; lwz 0,0x0(9); stw 0,0x0(3); lwz 0,0x4(9); stw 0,0x4(3); b 10f; 2:; lwz 9,0x118(31); cmpwi 9,0; beq 5f; lwz 0,0x8(9); andi. 11,0,8192; beq 5f; lwz 9,0x4(31); addi 11,31,296; li 10,240; mr 28,11; addis 9,9,3; addi 30,1,8; addi 9,9,-25480; 3:; lwz 0,0x0(9); addic. 10,10,-24; stw 0,0x0(11); lwz 0,0x4(9); stw 0,0x4(11); lwz 0,0x8(9); stw 0,0x8(11); lwz 0,0xc(9); stw 0,0xc(11); lwz 0,0x10(9); stw 0,0x10(11); lwz 0,0x14(9); addi 9,9,24; stw 0,0x14(11); addi 11,11,24; bne 3b; lwz 0,0x0(9); stw 0,0x0(11); lwz 0,0x4(9); stw 0,0x4(11); lwz 0,0x8(31); cmpwi 0,0; beq 6f; lwz 9,0x4(31); addi 11,31,544; li 10,240; addis 9,9,3; addi 9,9,-25480; 4:; lwz 0,0x0(9); addic. 10,10,-24; stw 0,0x0(11); lwz 0,0x4(9); stw 0,0x4(11); lwz 0,0x8(9); stw 0,0x8(11); lwz 0,0xc(9); stw 0,0xc(11); lwz 0,0x10(9); stw 0,0x10(11); lwz 0,0x14(9); addi 9,9,24; stw 0,0x14(11); addi 11,11,24; bne 4b; lwz 0,0x0(9); stw 0,0x0(11); lwz 0,0x4(9); stw 0,0x4(11); b 6f; 5:; addi 30,31,296; addi 29,31,256; mr 5,30; mr 3,31; mr 4,29; li 6,0; bl _s8004F8D8_0; mr 28,30; lwz 0,0x8(31); addi 30,1,8; cmpwi 0,0; beq 6f; mr 4,29; mr 3,31; addi 5,31,544; li 6,1; bl _s8004F8D8_1; 6:; li 11,0; lis 9,-32697; stw 11,0x8(1); addi 9,9,24012; stw 11,0x4(30); lwz 0,0x358(9); cmpwi 0,0; bne 10f; lwz 0,0xcc(9); cmpwi 0,0; bne 7f; lwz 0,0x32c(31); andi. 9,0,1; beq 7f; li 0,1; stw 0,0x8(1); 7:; lis 9,-32697; lwz 9,0x5e98(9); cmpwi 9,1; bne 8f; lwz 0,0x32c(31); andi. 11,0,8; beq 8f; stw 9,0x4(30); 8:; lwz 0,0x8(1); cmpwi 0,0; bne 9f; lwz 0,0x4(30); cmpwi 0,0; beq 10f; 9:; mr 3,31; mr 4,28; mr 5,30; bl _s8004F8D8_2; 10:; lwz 0,0x24(1); mtspr 8,0; lmw 28,0x10(1); addi 1,1,32"

extern "C" void _s8004F8D8_0();
extern "C" void _s8004F8D8_1();
extern "C" void _s8004F8D8_2();

struct ISimsObjectModel {
    void DoLightingCalculation();
};

void ISimsObjectModel::DoLightingCalculation() {
}
