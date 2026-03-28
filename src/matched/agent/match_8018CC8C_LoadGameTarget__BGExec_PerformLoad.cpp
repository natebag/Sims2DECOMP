static int s_loadComplete;

class LoadGameTarget {
public:
    void PerformLoad(void);
    static void BGExec_PerformLoad(void* data);
};

void LoadGameTarget::BGExec_PerformLoad(void* data) {
    if (data) {
        ((LoadGameTarget*)data)->PerformLoad();
    }
    s_loadComplete = 1;
}
