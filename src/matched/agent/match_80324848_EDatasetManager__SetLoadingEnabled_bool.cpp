static int s_loadingEnabled;
class EDatasetManager { public: static void SetLoadingEnabled(int); };
void EDatasetManager::SetLoadingEnabled(int val) { s_loadingEnabled = val; }
