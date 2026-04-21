// 0x8032F5EC (68B) ENgcGraphics::SetBackgroundColor(EVec3 &, int, bool)
// Forward to base, then dispatch SetClearColor to renderer singleton.

class EVec3;

class EGraphics {
public:
    void SetBackgroundColor(EVec3& c, int idx, bool noApply);
};

class ENgcRenderer {
public:
    void SetClearColor(EVec3& c, bool noApply);
};

extern char s_renderer[];

class ENgcGraphics : public EGraphics {
public:
    void SetBackgroundColor(EVec3& c, int idx, bool noApply);
};

void ENgcGraphics::SetBackgroundColor(EVec3& c, int idx, bool noApply) {
    EGraphics::SetBackgroundColor(c, idx, noApply);
    ((ENgcRenderer*)s_renderer)->SetClearColor(c, noApply);
}
