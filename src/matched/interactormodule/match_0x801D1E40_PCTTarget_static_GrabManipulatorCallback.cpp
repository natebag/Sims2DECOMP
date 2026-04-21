// 0x801D1E40 PCTTarget::static_GrabManipulatorCallback(InteractorModule::Interactor::CallbackData*) (48B)
// Session 12 Track C template-family scout — Candidate #1 pioneer.
// Forward-to-non-static thunk template. 5-member family all byte-identical
// modulo bl target (which is relocation-masked). See commit message for
// the sibling template recipe.

namespace InteractorModule {
    namespace Interactor {
        struct CallbackData;
    }
}

struct PCTTarget {
    static void static_GrabManipulatorCallback(InteractorModule::Interactor::CallbackData* data);
    void GrabManipulatorCallback(InteractorModule::Interactor::CallbackData* data);
};

void PCTTarget::static_GrabManipulatorCallback(InteractorModule::Interactor::CallbackData* data) {
    PCTTarget* self = *(PCTTarget**)((char*)data + 4);
    if (self != 0) {
        self->GrabManipulatorCallback(data);
    }
}
