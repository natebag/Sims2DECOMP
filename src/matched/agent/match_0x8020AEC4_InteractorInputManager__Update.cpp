// 0x8020AEC4 (108B) InteractorModule::InteractorInputManager::Update(float)
// Iterates over m_count InstanceData elements (32B each), calling InstanceData::Update(dt).
// r29=byte_offset, r31=counter; GCC strength-reduces array index to running offset.

namespace InteractorModule {

struct InstanceData {
    char pad[32];
    void Update(float dt);
};

struct InteractorInputManager {
    InstanceData* m_instances;
    int m_count;

    void Update(float dt);
};

void InteractorInputManager::Update(float dt) {
    for (int i = 0; i < m_count; i++) {
        m_instances[i].Update(dt);
    }
}

}
