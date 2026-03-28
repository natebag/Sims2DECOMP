// 0x80079C34 (8 bytes)
class CUnlockDisplayObject {
public:
    float GetRadius();
};

float CUnlockDisplayObject::GetRadius() {
    return *(float*)((char*)this + 0x28);
}
