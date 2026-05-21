// 0x8021F00C InteractorModule::SimInteractor::ChooseAction(Interaction*) (104B)
// Same MI-vcall pattern as DirectInteractor::ChooseAction (p+4 vtable, offsets 0xB0/0xB4).
// Adds a null-person guard: GetPerson called twice — once to check, once to fetch for vtable walk.

struct Interaction;
struct Person;

extern Person* Interaction_GetPerson(Interaction* self);

namespace InteractorModule {
    class SimInteractor {
    public:
        static int ChooseAction(void* self, Interaction* iface);
    };
}

int InteractorModule::SimInteractor::ChooseAction(void* self, Interaction* iface) {
    if (!iface || !Interaction_GetPerson(iface)) return 0;
    Person* p = Interaction_GetPerson(iface);
    char* vt = *(char**)((char*)p + 4);
    short thisOff = *(short*)(vt + 0xB0);
    int (*fn)(void*, Interaction*) =
        *(int(**)(void*, Interaction*))(vt + 0xB4);
    return fn((char*)p + thisOff, iface);
}
