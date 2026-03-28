class ITBTarget {
public:
    float GetUserReadTime(void);
};

class H2DTarget {
public:
    char _pad[0xC4];
    ITBTarget *m_itbTarget;

    int IsUserReadingIntroThoughtBalloon(void);
};

int H2DTarget::IsUserReadingIntroThoughtBalloon(void) {
    int result = 0;
    if (m_itbTarget != 0) {
        if (m_itbTarget->GetUserReadTime() > 0.0f) {
            result = 1;
        }
    }
    return result;
}
