// 0x801BDA50 (8 bytes)
class ITBTarget {
public:
    float GetUserReadTime();
};

float ITBTarget::GetUserReadTime() {
    return *(float*)((char*)this + 0x9C);
}
