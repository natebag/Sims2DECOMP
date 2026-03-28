void AptViewer_CallFunction(char* target, int a, int b, int c, int d);

extern char g_exitFlowTarget[];

class E2ETarget {
public:
    int IsEyeToyPluggedIn(void);
    void OnExitDialog(int result);
};

void E2ETarget::OnExitDialog(int result) {
    if (IsEyeToyPluggedIn() == 0) {
        AptViewer_CallFunction(g_exitFlowTarget, 0, 0, 0, 0);
    }
}
