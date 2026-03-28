static int s_isResetting;
class ENgcEngine { public: static int IsResetting(); };
int ENgcEngine::IsResetting() { return s_isResetting; }
