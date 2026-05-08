// EIObjTileBoundRect::Set(EVec2 &) at 0x80055D3C (52 bytes)
// Sets rect to a 1x1 square centered at v (xMin/xMax/yMin/yMax).

struct EVec2 { float x, y; };

struct EIObjTileBoundRect_S {
    float xMin;  // 0
    float xMax;  // 4
    float yMin;  // 8
    float yMax;  // 12
    void Set(EVec2& v);
};

void EIObjTileBoundRect_S::Set(EVec2& v) {
    float vx = v.x;
    float vy = v.y;
    xMin = vx - 0.5f;
    xMax = vx + 0.5f;
    yMin = vy - 0.5f;
    yMax = vy + 0.5f;
}
