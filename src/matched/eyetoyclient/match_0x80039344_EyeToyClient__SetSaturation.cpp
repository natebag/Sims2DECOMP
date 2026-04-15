/* EyeToyClient::SetSaturation(float) - 0x80039344 (52B) */

extern char g_EyeToyFilter[100];  // at 0x80475A60

class ImageProcessingManager {
public:
    static int SetStageFilter(int stage, char* filter);
};

class EyeToyClient {
public:
    static void SetSaturation(float f);
};

void EyeToyClient::SetSaturation(float f) {
    char* filter = g_EyeToyFilter;
    *(float*)(filter + 28) = f + f;
    ImageProcessingManager::SetStageFilter(0, filter);
}
