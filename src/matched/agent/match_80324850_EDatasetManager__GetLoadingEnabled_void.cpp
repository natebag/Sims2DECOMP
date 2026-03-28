static int s_loadingEnabled;
class EDatasetManager { public: static int GetLoadingEnabled(); };
int EDatasetManager::GetLoadingEnabled() { return s_loadingEnabled; }
