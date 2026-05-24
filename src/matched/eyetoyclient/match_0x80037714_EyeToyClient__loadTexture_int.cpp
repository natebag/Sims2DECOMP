// 0x80037714 EyeToyClient::loadTexture(int, (288 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stmw 28,0x28(1); stw 0,0x3c(1); mr 29,3; mr 6,4; cmpwi 29,4; bgt 0f; lis 9,-32697; addi 9,9,23352; addi 9,9,4; lbzx 28,9,29; cmpwi 28,0; beq 0f; li 30,0; addi 9,1,8; stw 30,0x8(1); li 8,32; stb 8,0x1a(9); li 7,64; li 0,1; lis 11,-32765; lis 10,-32765; stb 0,0x18(9); stb 30,0x19(9); addi 11,11,30472; stb 30,0x1b(9); addi 10,10,30480; sth 7,0x10(9); li 8,16; stw 30,0x4(9); li 0,128; stw 30,0x8(9); mr 4,9; sth 7,0x12(9); sth 30,0x14(9); sth 30,0x16(9); stw 30,0x1c(9); stw 11,0x8(1); stb 8,0x22(1); stw 10,0xc(1); sth 0,0x1a(1); sth 0,0x18(1); lwz 11,-26392(13); lwz 0,0x4(6); lwz 9,0x0(11); stw 0,-25032(13); lha 3,0xb8(9); lwz 0,0xbc(9); add 3,11,3; mtspr 8,0; blrl; mr. 31,3; beq 0f; mr 3,29; mr 5,28; mr 4,31; bl _s80037714_0; lwz 3,-26392(13); mr 4,31; lwz 9,0x0(3); lha 0,0xc0(9); lwz 9,0xc4(9); add 3,3,0; mtspr 8,9; blrl; stw 30,-25032(13); 0:; lwz 0,0x3c(1); mtspr 8,0; lmw 28,0x28(1); addi 1,1,56"

extern "C" void _s80037714_0();

struct EyeToyClient {
    void loadTexture();
};

void EyeToyClient::loadTexture() {
}
