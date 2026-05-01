// 0x802093AC InteractorModule::Interactor::ResetInputState(void) (68B)
// PERMUTER CANDIDATE — register-allocation wall
//
// Attempted ~15 source variants including:
//   - struct F { float v; } wrappers
//   - volatile float arrays and unions
//   - pointer arithmetic for stack slots
//   - named locals vs array indexing
//   - -fno-schedule-insns flag
//
// Wall: store order matches individually, load order matches individually,
// but never simultaneously with the correct registers (r0/r9/r10/r11).
// The compiler either:
//   (a) uses addi r11,r1,8 but loads 4(r11) before 8(r1) (wrong load order), or
//   (b) uses addi r9,r1,8 and loads 8(r1) first but assigns it to r11 (wrong register)
//
// DOL expected sequence:
//   stfs f0,4(r11); stfs f0,8(r1); stw r10,68(r3); lwz r9,4(r11); lwz r0,8(r1);
//   stw r0,60(r3); stw r9,56(r3); stw r9,64(r3); stw r0,52(r3); stw r10,72(r3)
//
// FLAGS: -fno-schedule-insns

struct Interactor {
    char pad[52];
    int m_field52;
    int m_field56;
    int m_field60;
    int m_field64;
    int m_field68;
    int m_field72;
    void ResetInputState();
};

void Interactor::ResetInputState() {
    volatile float vals[2];
    vals[0] = 0.0f;
    vals[1] = vals[0];
    m_field68 = 1;
    int bits0 = *(int*)&vals[0];
    int bits1 = *(int*)&vals[1];
    *(volatile int*)((char*)this + 60) = bits0;
    *(volatile int*)((char*)this + 56) = bits1;
    *(volatile int*)((char*)this + 64) = bits1;
    *(volatile int*)((char*)this + 52) = bits0;
    m_field72 = 1;
}
