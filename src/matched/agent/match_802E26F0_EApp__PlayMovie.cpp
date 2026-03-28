class EApp {
public:
    char m_pad1[1104];
    int m_moviePlayingState;
    int m_movieStarting;
    int m_movieResId;
    int m_movieWidth;
    int m_movieHeight;
    void PlayMovie(unsigned int resId, int width, int height);
};
void EApp::PlayMovie(unsigned int resId, int width, int height) {
    if (resId == 0) return;
    m_movieStarting = 1;
    m_movieResId = resId;
    m_movieWidth = width;
    m_movieHeight = height;
}
