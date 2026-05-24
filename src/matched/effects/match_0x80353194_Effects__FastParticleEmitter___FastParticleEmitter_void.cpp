// 0x80353194 Effects::FastParticleEmitter::~FastParticleEmitter(void) (260 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; lis 9,-32697; lwz 11,0x18c(31); addi 9,9,-10672; mr 30,4; stw 9,0x144(31); cmpwi 11,0; beq 1f; lwz 0,0x1a0(31); cmpwi 0,0; bne 1f; lwz 4,0xc0(11); cmpwi 4,0; beq 0f; lis 3,-32692; li 5,1; addi 3,3,-7364; bl _s80353194_0; 0:; bl _s80353194_1; lwz 4,0x18c(31); bl _s80353194_2; 1:; mr 3,31; bl _s80353194_3; lwz 0,0x190(31); cmpwi 0,0; beq 2f; lwz 0,0x1a0(31); mr 3,0; cmpwi 0,0; bne 3f; bl _s80353194_4; lwz 4,0x190(31); bl _s80353194_5; 2:; lwz 0,0x1a0(31); mr 3,0; cmpwi 0,0; beq 4f; 3:; bl _s80353194_6; 4:; lwz 4,0x1a4(31); cmpwi 4,0; beq 5f; lwz 3,-26392(13); lwz 9,0x0(3); lha 0,0x110(9); lwz 9,0x114(9); add 3,3,0; mtspr 8,9; blrl; 5:; lis 9,-32697; andi. 0,30,1; addi 9,9,-10728; stw 9,0x144(31); beq 6f; bl _s80353194_7; mr 4,31; bl _s80353194_8; 6:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"

extern "C" void _s80353194_0();
extern "C" void _s80353194_1();
extern "C" void _s80353194_2();
extern "C" void _s80353194_3();
extern "C" void _s80353194_4();
extern "C" void _s80353194_5();
extern "C" void _s80353194_6();
extern "C" void _s80353194_7();
extern "C" void _s80353194_8();

struct Effects {
    void FastParticleEmitter___FastParticleEmitter();
};

void Effects::FastParticleEmitter___FastParticleEmitter() {
}
