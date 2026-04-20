// 0x80205BB0 InteractorModule::DirectInteractor::ChooseAction(Interaction*) (84B)
// If iface != NULL: call GetPerson(iface), read MI secondary vtable (p+4),
// fetch this-adjustor offset + fn pointer, invoke via blrl.
// Session 12 Track C Manipulator pioneer — Technique #56 (MI-vcall via p+4).

struct Interaction;
struct Person;

extern Person* Interaction_GetPerson(Interaction* self);

namespace InteractorModule {
    class DirectInteractor {
    public:
        static int ChooseAction(void* self, Interaction* iface);
    };
}

int InteractorModule::DirectInteractor::ChooseAction(void* self, Interaction* iface) {
    if (iface == 0) return 0;
    Person* p = Interaction_GetPerson(iface);
    char* vt = *(char**)((char*)p + 4);              // secondary vtable at p+4
    short thisOff = *(short*)(vt + 0xB0);             // adjustor offset
    int (*fn)(void*, Interaction*) =
        *(int(**)(void*, Interaction*))(vt + 0xB4);
    return fn((char*)p + thisOff, iface);
}
