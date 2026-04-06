// 0x802F1F9C EGraphics::GetFrameBufferTextureCoordinate (24b)

typedef struct { float x, y; } EVec2;

void GetFrameBufferTextureCoordinate(void* this_, EVec2* result, EVec2 coord) {
    result->x = coord.x;
    result->y = coord.y;
}
