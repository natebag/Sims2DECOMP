static const char s_appName[] = "TheSims2";
class EApp { public: static const char *GetAppName(); };
const char *EApp::GetAppName() { return s_appName; }
