// 0x802E26F0 EApp::PlayMovie(unsigned int, int, int) (32 B)
// FLAGS: -fno-schedule-insns
//
// Early-out if arg0 == 0, else store all args + m_active=1.
// asm:
//   mr. r4, r4
//   beqlr
//   li r0, 1
//   stw r6, 0x464(r3)
//   stw r4, 0x45c(r3)
//   stw r0, 0x454(r3)
//   stw r5, 0x460(r3)
//   blr

struct EApp {
    char pad[0x454];
    int m_active;
    char pad2[0x45c - 0x458];
    int m_field45c;
    int m_field460;
    int m_field464;

    void PlayMovie(unsigned int a, int b, int c);
};

void EApp::PlayMovie(unsigned int a, int b, int c) {
    if (a == 0) return;
    m_field464 = c;
    m_field45c = a;
    m_active = 1;
    m_field460 = b;
}
