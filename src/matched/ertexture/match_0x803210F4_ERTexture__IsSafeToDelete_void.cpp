// 0x803210F4 ERTexture::IsSafeToDelete(void) (140 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; lwz 0,0x14(30); cmpwi 0,0; beq 3f; lwz 0,-26312(13); cmpwi 0,0; bne 1f; b 3f; 0:; li 3,0; b 4f; 1:; li 31,0; 2:; lwz 11,-26312(13); mr 4,31; lwz 9,0x338(11); lwz 0,0x1c(9); lha 3,0x18(9); mtspr 8,0; add 3,11,3; blrl; lwz 0,0x14(30); cmpw 3,0; beq 0b; addi 31,31,1; cmpwi 31,1; ble 2b; 3:; li 3,1; 4:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"

struct ERTexture {
    void IsSafeToDelete();
};

void ERTexture::IsSafeToDelete() {
}
