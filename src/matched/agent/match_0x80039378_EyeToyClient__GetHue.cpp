// EyeToyClient::GetHue() at 0x80039378 (56 bytes)
// Static-data hue normalization with literal float constants.
// m_hue at 0x80475A78 (static member). Constants 180.0f/360.0f at 0x803D16E0/E4.

extern char gv_EyeToyClient_m_hue[16];

class EyeToyClient {
public:
    static float GetHue();
};

float EyeToyClient::GetHue() {
    float hue = *(float*)gv_EyeToyClient_m_hue;
    if (hue > 180.0f) {
        hue -= 360.0f;
    }
    hue += 180.0f;
    return hue / 360.0f;
}
