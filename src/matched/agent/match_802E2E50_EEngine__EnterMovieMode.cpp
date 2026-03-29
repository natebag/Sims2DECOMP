// EEngine::EnterMovieMode(void)
// 0x802E2E50 | 60 bytes
// Calls EyeToyManager::PauseStreams(), then _pResLoader->PauseLoads()
// _pResLoader->PauseLoads() is at vtable offset 0x108 (entry 33)

class EResourceManager;
class EFile;
class EResLoadCmdResult;

class EResourceLoader {
public:
    virtual ~EResourceLoader();
    virtual void Init();
    virtual void Shutdown();
    virtual void TerminateThread();
    virtual bool IsCallingThread();
    virtual void Update();
    virtual void FlushCommandQueue();
    virtual void AddManager(EResourceManager*);
    virtual void RemoveManager(EResourceManager*);
    virtual void Load(EResourceManager*, unsigned int, EFile*, unsigned int, unsigned int, bool);
    virtual void CollapseDelRef(EResourceManager*, unsigned int);
    virtual void Unload(EResourceManager*, unsigned int);
    virtual bool IsInQueue(EResourceManager*, unsigned int);
    virtual void ReadData(EFile*, void*, unsigned int, unsigned int, bool, EResLoadCmdResult*);
    virtual void ReadData(EResourceManager*, void*, unsigned int, unsigned int, bool, EResLoadCmdResult*);
    virtual void WriteData(EFile*, void*, unsigned int, unsigned int, bool, EResLoadCmdResult*);
    virtual void GetQueueStats(int&, int&, int&, int&);
    virtual void GetQueuedCommandCount();
    virtual bool IsBusy();
    virtual void FindResourceManager(char*);
    virtual void OpenFiles();
    virtual void CloseArchiveFile(EResourceManager*);
    virtual void AddRefDelRefAllResources();
    virtual void PrintLoadedResources();
    virtual void PrintLoadedResources(char*);
    virtual void PrintResourceSizes();
    virtual void PrintResourceSizes(char*);
    virtual void FreeUnreferencedResources();
    virtual void FreeUnreferencedResources(char*);
    virtual void GetUnreferencedResourceCount();
    virtual void GetUnreferencedResourceCount(char*);
    virtual void EnableReloads(bool);
    virtual void PauseLoads();     // vtable entry 33 = offset 0x108
    virtual void UnPauseLoads();   // vtable entry 34 = offset 0x110
    virtual bool AreLoadsPaused(); // vtable entry 35 = offset 0x118
};

void EyeToyManager_PauseStreams();

class EEngine {
public:
    void EnterMovieMode();
};

extern EResourceLoader* _pResLoader;

void EEngine::EnterMovieMode() {
    EyeToyManager_PauseStreams();
    _pResLoader->PauseLoads();
}
