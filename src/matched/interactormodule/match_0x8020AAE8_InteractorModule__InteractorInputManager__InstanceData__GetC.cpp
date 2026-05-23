// 0x8020AAE8 InteractorModule::InteractorInputManager::InstanceData::GetC(void) (8 B)
namespace InteractorModule { namespace InteractorInputManager {
struct InstanceData { char _pad[0x14]; unsigned m_c; unsigned GetC(); };
} }
unsigned InteractorModule::InteractorInputManager::InstanceData::GetC() { return m_c; }
