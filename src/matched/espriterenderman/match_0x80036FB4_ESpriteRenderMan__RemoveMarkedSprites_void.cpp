// 0x80036FB4 ESpriteRenderMan::RemoveMarkedSprites(void) (148 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 29,3; lwz 4,0x0(29); cmpwi 4,0; beq 3f; 0:; lwz 31,0x0(4); lwz 30,0x8(4); lwz 0,0x0(31); cmpwi 0,0; beq 1f; mr 3,29; bl _s80036FB4_0; cmpwi 31,0; beq 2f; lwz 9,0xe8(31); li 4,3; lha 3,0x8(9); lwz 0,0xc(9); add 3,31,3; mtspr 8,0; blrl; b 2f; 1:; lwz 0,0x4(31); cmpwi 0,0; beq 2f; mr 3,31; bl _s80036FB4_1; 2:; mr. 4,30; bne 0b; 3:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"

extern "C" void _s80036FB4_0();
extern "C" void _s80036FB4_1();

struct ESpriteRenderMan {
    void RemoveMarkedSprites();
};

void ESpriteRenderMan::RemoveMarkedSprites() {
}
