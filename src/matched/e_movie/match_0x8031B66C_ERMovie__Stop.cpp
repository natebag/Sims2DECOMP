// 0x8031B66C (64B) ERMovie::Stop(void)
struct ERMovieBaseBase { int m_0; int m_4; };
struct ERMovieBase : public ERMovieBaseBase {
    virtual ~ERMovieBase() = 0;
    virtual void Start(int, int) = 0;
    virtual void Stop() = 0;
    virtual void Reset() = 0;
    virtual int IsFinished() = 0;
    virtual void Update() = 0;
};
struct ERMovie {
    char pad[36];
    ERMovieBase* m_24;
    void Stop();
};
void ERMovie::Stop() {
    if (m_24) m_24->Stop();
}
