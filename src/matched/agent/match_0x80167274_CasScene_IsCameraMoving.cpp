// 0x80167274 (60B) CasScene::IsCameraMoving(void)
// True iff m_field2728 < 1.0 AND m_field2732 <= 0.0.

extern float g_const_one;   // SDA @ -748 (1.0f)
extern float g_const_zero;  // SDA @ -744 (0.0f)

class CasScene {
public:
    char _pad[2728];
    float m_field2728;  // +2728
    float m_field2732;  // +2732
    int IsCameraMoving();
};

int CasScene::IsCameraMoving()
{
    int result = 0;
    if (m_field2728 < 1.0f) {
        if (m_field2732 <= 0.0f) {
            result = 1;
        }
    }
    return result;
}
