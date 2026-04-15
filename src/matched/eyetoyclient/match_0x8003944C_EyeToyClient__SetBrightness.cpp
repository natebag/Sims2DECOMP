/* EyeToyClient::SetBrightness(float) - 0x8003944C (52B) */

extern char g_EyeToyFilter[100];

class ImageProcessingManager {
public:
    static int SetStageFilter(int stage, char* filter);
};

class EyeToyClient {
public:
    static void SetBrightness(float f);
};

void EyeToyClient::SetBrightness(float f) {
    char* filter = g_EyeToyFilter;
    *(float*)(filter + 32) = f + f;
    ImageProcessingManager::SetStageFilter(0, filter);
}
