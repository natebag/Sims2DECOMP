// 0x8031B72C (92B) ERMovie::IsFinished(void)
// goto-shared-label: null path and result-nonzero path share the `r=1` block
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
    int IsFinished();
};
int ERMovie::IsFinished() {
    int r = 0;
    if (!m_24) goto set_one;
    if (!m_24->IsFinished()) goto done;
set_one:
    r = 1;
done:
    return r;
}
