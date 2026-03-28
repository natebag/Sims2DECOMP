/* ESimsApp::TakeBigScreenshot(int, int) at 0x80005D2C (20B) */

struct ESimsApp {
    char pad[0x49C];
    int m_takingScreenshot;
    int m_screenshotWidth;
    int m_screenshotHeight;

    void TakeBigScreenshot(int width, int height);
};

void ESimsApp::TakeBigScreenshot(int width, int height) {
    m_takingScreenshot = 1;
    m_screenshotWidth = width;
    m_screenshotHeight = height;
}
