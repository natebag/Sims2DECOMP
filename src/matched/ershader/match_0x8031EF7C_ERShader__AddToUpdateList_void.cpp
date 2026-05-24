// 0x8031EF7C ERShader::AddToUpdateList(void) (196 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lwz 0,0x54(31); cmpwi 0,0; bne 2f; lis 3,-32692; li 4,12; li 5,8; addi 3,3,-17444; bl _s8031EF7C_0; stw 3,0x54(31); lis 11,-32693; stw 31,0x0(3); addi 0,11,6072; li 4,-1; lwz 9,0x17b8(11); lha 3,0x10(9); lwz 9,0x14(9); add 3,3,0; mtspr 8,9; blrl; lwz 3,0x54(31); lwz 0,-22616(13); stw 0,0x4(3); lwz 9,-22616(13); cmpwi 9,0; beq 0f; stw 3,0x8(9); b 1f; 0:; stw 3,-22620(13); 1:; li 0,0; lis 11,-32693; stw 0,0x8(3); addi 10,11,6072; stw 3,-22616(13); lwz 9,0x17b8(11); lha 3,0x18(9); lwz 0,0x1c(9); add 3,3,10; mtspr 8,0; blrl; 2:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"

extern "C" void _s8031EF7C_0();

struct ERShader {
    void AddToUpdateList();
};

void ERShader::AddToUpdateList() {
}
