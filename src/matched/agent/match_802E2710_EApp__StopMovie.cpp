class EApp {
public:
    char m_pad[1108];
    int m_moviePlaying;
    void StopMovie();
};
void EApp::StopMovie() { m_moviePlaying = 0; }
