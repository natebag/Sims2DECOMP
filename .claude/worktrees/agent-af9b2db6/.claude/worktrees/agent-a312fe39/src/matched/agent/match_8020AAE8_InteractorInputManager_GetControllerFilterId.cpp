// 0x8020AAE8 (8 bytes) - InteractorModule::InteractorInputManager::InstanceData::GetControllerFilterId(void) const
// lwz r3, 20(r3); blr  =>  return this->m_controllerFilterId;

struct InstanceData {
    char pad[0x14];
    int m_controllerFilterId;

    int GetControllerFilterId() const;
};

int InstanceData::GetControllerFilterId() const {
    return m_controllerFilterId;
}
