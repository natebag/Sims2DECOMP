// 0x8004EF58 ISimsObjectModel::PreloadAnimation(short) (212 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; lwz 5,-32420(13); lis 29,-32693; bl _s8004EF58_0; lwz 4,0x4b4(30); mr 31,3; cmpwi 4,0; beq 1f; lwz 0,0x8(31); cmpw 4,0; bne 0f; addi 3,29,11064; bl _s8004EF58_1; cmpwi 3,0; beq 3f; lwz 4,0x4b4(30); addi 3,29,11064; li 5,1; bl _s8004EF58_2; li 0,0; li 3,0; li 4,1; stw 0,0x4b4(30); b 4f; 0:; addi 3,29,11064; bl _s8004EF58_3; li 0,0; stw 0,0x4b4(30); 1:; lis 3,-32693; lwz 4,0x8(31); addi 3,3,11064; bl _s8004EF58_4; cmpwi 3,0; beq 2f; li 3,0; li 4,1; b 4f; 2:; lwz 0,0x8(31); addi 3,29,11064; mr 4,0; stw 0,0x4b4(30); bl _s8004EF58_5; 3:; li 3,0; li 4,0; 4:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"

extern "C" void _s8004EF58_0();
extern "C" void _s8004EF58_1();
extern "C" void _s8004EF58_2();
extern "C" void _s8004EF58_3();
extern "C" void _s8004EF58_4();
extern "C" void _s8004EF58_5();

struct ISimsObjectModel {
    void PreloadAnimation_short();
};

void ISimsObjectModel::PreloadAnimation_short() {
}
