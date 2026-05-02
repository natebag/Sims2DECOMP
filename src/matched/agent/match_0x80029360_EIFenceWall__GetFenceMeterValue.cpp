// EIFenceWall::GetFenceMeterValue(void) - 0x80029360 (64 bytes)
// Signed-int-to-float conversion via xoris + magic-double idiom,
// then divide by non-SDA float constant.
//
// FLAGS: -msdata=eabi -G 8

extern int g_fenceMeterCounter;
extern char g_fenceMeterDivisor[16];

struct EIFenceWall {
    float GetFenceMeterValue();
};

float EIFenceWall::GetFenceMeterValue() {
    return (float)g_fenceMeterCounter / *(float*)g_fenceMeterDivisor;
}
