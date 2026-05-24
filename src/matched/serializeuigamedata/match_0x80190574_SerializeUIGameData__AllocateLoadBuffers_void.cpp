// 0x80190574 SerializeUIGameData::AllocateLoadBuffers(void) (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); lis 9,-32701; li 28,0; addi 30,9,27664; li 31,0; li 29,4; 0:; lwzx 0,31,30; cmpwi 0,0; beq 1f; bl _s80190574_0; lwzx 4,31,30; bl _s80190574_1; stwx 28,31,30; 1:; bl _s80190574_2; li 4,1024; li 5,0; bl _s80190574_3; stwx 3,31,30; addic. 29,29,-1; addi 31,31,4; bne 0b; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"

extern "C" void _s80190574_0();
extern "C" void _s80190574_1();
extern "C" void _s80190574_2();
extern "C" void _s80190574_3();

struct SerializeUIGameData {
    void AllocateLoadBuffers();
};

void SerializeUIGameData::AllocateLoadBuffers() {
}
