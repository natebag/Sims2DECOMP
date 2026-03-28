class EAnimController {
public:
    void Deallocate();
    void Shutdown();
};
void EAnimController::Shutdown() { Deallocate(); }
