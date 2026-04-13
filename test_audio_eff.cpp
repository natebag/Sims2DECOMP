// FLAGS: -fno-elide-constructors

struct FrameEffect {
    char pad[12];
    int field;
    int IsEffectRamping() const;
};

int FrameEffect::IsEffectRamping() const {
    return (this->field == 2 ? 1 : 0) | (this->field == 8 ? 1 : 0);
}
