// 0x802137C0 (104B) InteractorModule::ClearCameraFilter(int)
// Sibling of SetCameraFilter; clears (no GetControllerFilterId, just clears).

namespace InteractorModule {
    class InstanceData;

    class InteractorInputManager {
    public:
        InstanceData* GetSessionData(int idx);
    };

    class InteractorManager {
    public:
        static InteractorInputManager* GetInputManager();
    };

    int ClearCameraFilter(int filterId);
}

class ESimsCam {
public:
    void ClearControllerFilterId();
};

class CameraManager {
public:
    static CameraManager* GetSingleton();
    ESimsCam* GetCamera(int idx);
};

int InteractorModule::ClearCameraFilter(int filterId) {
    InteractorInputManager* inputMgr = InteractorManager::GetInputManager();
    if (inputMgr->GetSessionData(filterId) == 0) {
        return 0;
    }
    CameraManager* camMgr = CameraManager::GetSingleton();
    ESimsCam* camera = camMgr->GetCamera(filterId);
    if (camera == 0) {
        return 0;
    }
    camera->ClearControllerFilterId();
    return 1;
}
