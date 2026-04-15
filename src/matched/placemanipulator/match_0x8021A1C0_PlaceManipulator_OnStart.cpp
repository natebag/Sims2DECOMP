// 0x8021A1C0 InteractorModule::PlaceManipulator::OnStart(InteractorModule::Interactor::InteractorParams *) (60B)

struct InteractorParams;
struct PlaceManipulatorParams;

struct ObjectManipulator {
    void OnStart(InteractorParams*);
};

struct PlaceManipulator : ObjectManipulator {
    void StartPlacement(PlaceManipulatorParams*);
    void OnStart(InteractorParams* params);
};

void PlaceManipulator::OnStart(InteractorParams* params) {
    ObjectManipulator::OnStart(params);
    StartPlacement((PlaceManipulatorParams*)params);
}
