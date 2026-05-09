// PRAGMA_STUB: EIObjTileBoundRect::GetCenter(EVec2 &)
// EIObjTileBoundRect::GetCenter(EVec2 &) at 0x80055E30 (52 bytes)
// Returns the midpoint of the rect via reference output.

struct EVec2 { float x, y; };

struct EIObjTileBoundRect_GC {
    float xMin;
    float xMax;
    float yMin;
    float yMax;
    void GetCenter(EVec2& v);
};

void EIObjTileBoundRect_GC::GetCenter(EVec2& v) {
    v.x = (xMax - xMin) * 0.5f + xMin;
    v.y = (yMax - yMin) * 0.5f + yMin;
}
