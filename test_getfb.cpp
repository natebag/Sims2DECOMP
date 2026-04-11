class EVec2 {
public:
    float x;
    float y;
};

class EGraphics {
public:
    EVec2 GetFrameBufferTextureCoordinate(EVec2* input);
};

EVec2 EGraphics::GetFrameBufferTextureCoordinate(EVec2* input) {
    return *input;
}
