// 0x8021374C (116B) InteractorModule::SetCameraFilter(int)
// Lookup session + camera, set controller filter on resulting camera.

namespace InteractorModule {
    class InstanceData {
    public:
        unsigned int GetControllerFilterId() const;
    };

    class InteractorInputManager {
    public:
        InstanceData* GetSessionData(int idx);
    };

    class InteractorManager {
    public:
        static InteractorInputManager* GetInputManager();
    };

    int SetCameraFilter(int filterId);
}

class ESimsCam {
public:
    void SetControllerFilterId(unsigned int id);
};

class CameraManager {
public:
    static CameraManager* GetSingleton();
    ESimsCam* GetCamera(int idx);
};

int InteractorModule::SetCameraFilter(int filterId) {
    InteractorInputManager* inputMgr = InteractorManager::GetInputManager();
    InstanceData* sessionData = inputMgr->GetSessionData(filterId);
    if (sessionData == 0) {
        return 0;
    }
    CameraManager* camMgr = CameraManager::GetSingleton();
    ESimsCam* camera = camMgr->GetCamera(filterId);
    if (camera == 0) {
        return 0;
    }
    camera->SetControllerFilterId(sessionData->GetControllerFilterId());
    return 1;
}
