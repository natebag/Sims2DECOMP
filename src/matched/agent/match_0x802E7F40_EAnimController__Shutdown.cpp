struct EAnimController {
    void Deallocate();
    void Shutdown();
};

void EAnimController::Shutdown()
{
    Deallocate();
}
