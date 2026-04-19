// 0x802E271C (24B) EApp::IsMovieStarting(void)

struct EApp_IMS {
    char pad[1108];
    int m_movieStarting;
    int IsMovieStarting();
};

int EApp_IMS::IsMovieStarting() {
    return (unsigned)(m_movieStarting - 1) <= 1;
}
