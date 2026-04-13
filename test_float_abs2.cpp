struct FloatPool { float values[522]; };
#define g_pool (*(FloatPool*)0x803FE000)
void GetVelocity(float& v) {
    float f = g_pool.values[522];
    v = f;
}
