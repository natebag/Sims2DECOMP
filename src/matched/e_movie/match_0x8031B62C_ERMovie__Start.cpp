// 0x8031B62C (64B) ERMovie::Start(int, int)
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
    void Start(int a, int b);
};
void ERMovie::Start(int a, int b) {
    if (m_24) m_24->Start(a, b);
}
