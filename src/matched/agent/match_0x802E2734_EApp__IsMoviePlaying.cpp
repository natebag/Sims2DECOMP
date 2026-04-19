// 0x802E2734 (24B) EApp::IsMoviePlaying(void)

struct EApp_IMP {
    char pad[1104];
    int m_moviePlaying;
    int IsMoviePlaying();
};

int EApp_IMP::IsMoviePlaying() {
    return (unsigned)(m_moviePlaying - 1) <= 1;
}
