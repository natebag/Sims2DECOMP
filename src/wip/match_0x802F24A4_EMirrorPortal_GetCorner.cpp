// FLAGS: -fno-elide-constructors
// 0x802F24A4 (40 bytes)

struct Corner {
    float x, y, z;
};

// Explicit retptr pattern for struct return
void EMirrorPortal_GetCorner(void* retptr, int index, Corner* corners) {
    Corner* out = (Corner*)retptr;
    Corner* c = &corners[index];
    out->x = c->x;
    out->y = c->y;
    out->z = c->z;
}
