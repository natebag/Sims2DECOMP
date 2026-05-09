// GetCirclePointIX(EVec2&, float, EVec2&, EVec2&, Intersection&) at 0x800499F8 (64 bytes)
// Wrapper that calls GetCircleCircleIX with point degenerated to (0,0) circle of radius 0.

struct EVec2 {
    float x;
    float y;
};

struct Intersection;

extern void GetCircleCircleIX(EVec2&, float, EVec2&, EVec2&, float, EVec2&, Intersection&);

void GetCirclePointIX(EVec2& cA, float rA, EVec2& cB, EVec2& dirA, Intersection& res) {
    EVec2 zero;
    zero.y = 0.0f;
    zero.x = 0.0f;
    GetCircleCircleIX(cA, rA, cB, dirA, 0.0f, zero, res);
}
