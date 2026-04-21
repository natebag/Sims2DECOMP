// 0x80328E7C (20B) EyeToyManager::PauseStreams(void)
// Read SDA-relative global, set it to 1, return (old ^ 1).
// Trip-pattern that toggles caller-visible status while latching the new state.

extern int s_paused;

class EyeToyManager {
public:
    int PauseStreams();
};

int EyeToyManager::PauseStreams() {
    int old = s_paused;
    s_paused = 1;
    return old ^ 1;
}
