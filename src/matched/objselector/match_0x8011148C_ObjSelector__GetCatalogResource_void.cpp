// 0x8011148C ObjSelector::GetCatalogResource(void) (128 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 31,3; lwz 0,0x80(31); cmpwi 0,0; bne 0f; lwz 9,0x38(31); lha 27,0x52(9); bl _s8011148C_0; mr 28,3; lwz 30,0x0(28); mr 3,31; lha 29,0x10(30); addi 30,30,16; add 29,28,29; bl _s8011148C_1; lwz 0,0x4(30); mr 6,3; mr 3,29; mr 5,27; mr 4,31; mtspr 8,0; blrl; stw 28,0x80(31); 0:; lwz 3,0x80(31); lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"

extern "C" void _s8011148C_0();
extern "C" void _s8011148C_1();

struct ObjSelector {
    void GetCatalogResource();
};

void ObjSelector::GetCatalogResource() {
}
