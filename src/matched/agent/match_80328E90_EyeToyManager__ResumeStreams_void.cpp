static int s_streamsActive;
class EyeToyManager { public: int ResumeStreams(); };
int EyeToyManager::ResumeStreams() { int old = s_streamsActive; s_streamsActive = 0; return old; }
