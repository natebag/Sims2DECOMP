// 0x8039DB10 (16B) Intersection::Reset(void)

extern float Intersection_resetVal[3];  // 0x803D03BC

class Intersection {
public:
    void Reset();
};

void Intersection::Reset() {
    *(float*)((char*)this + 16) = Intersection_resetVal[0];
}
