static const char s_buildVersion[] = "F.09.12.0";
class EApp { public: static const char *GetBuildVersion(); };
const char *EApp::GetBuildVersion() { return s_buildVersion; }
