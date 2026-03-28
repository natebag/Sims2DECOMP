/* InteractorModule::InteractorManager::Update(float) at 0x8035AD78 (84 bytes) */
/* Contains two wrapper functions calling an internal at 0x8035AC94 */

namespace InteractorModule {

class InteractorManager {
public:
    void _InternalUpdate(int a, int b, int c);
    void Update(int a, int b);
    void ChangeActiveInteractorToNull(int a, int b, int c);
};

void InteractorManager::Update(int a, int b) {
    _InternalUpdate(a, b, 0);
}

void InteractorManager::ChangeActiveInteractorToNull(int a, int b, int c) {
    _InternalUpdate(b, c, a);
}

}
