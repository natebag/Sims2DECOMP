// 0x80090070 ELiveMode::IsRunningIntroCamera (24b)
struct ELiveMode {
    char pad[0x0C];
    int m_runningIntroCamera;
    int IsRunningIntroCamera();
};

int ELiveMode::IsRunningIntroCamera() {
    int result = 1;
    if (m_runningIntroCamera != 0) return result;
    result = 0;
    return result;
}
