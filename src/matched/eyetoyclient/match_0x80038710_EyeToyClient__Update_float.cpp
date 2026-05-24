// 0x80038710 EyeToyClient::Update(float) (164 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 0,-32576(13); cmpwi 0,-1; beq 2f; lwz 0,-32532(13); cmpwi 0,0; beq 0f; bl _s80038710_0; b 2f; 0:; lwz 0,-32568(13); cmpwi 0,-1; bne 1f; lwz 11,-32564(13); cmpwi 11,-1; beq 2f; lis 9,-32707; rlwinm 0,11,2,0,29; addi 9,9,5888; lis 3,-32692; lwzx 4,9,0; addi 3,3,-17444; stw 11,-32568(13); bl _s80038710_1; b 2f; 1:; lis 9,-32707; rlwinm 0,0,2,0,29; addi 9,9,5888; lis 3,-32692; lwzx 4,9,0; addi 3,3,-17444; bl _s80038710_2; cmpwi 3,0; stw 3,-32532(13); beq 2f; bl _s80038710_3; 2:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"

extern "C" void _s80038710_0();
extern "C" void _s80038710_1();
extern "C" void _s80038710_2();
extern "C" void _s80038710_3();

struct EyeToyClient {
    void Update();
};

void EyeToyClient::Update() {
}
