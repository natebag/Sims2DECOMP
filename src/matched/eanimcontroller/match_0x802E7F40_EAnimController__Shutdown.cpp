/* 0x802E7F40 (8 bytes) - EAnimController::Shutdown(void) */
class EAnimController {
public:
    void Deallocate();
    void Shutdown();
};

void EAnimController::Shutdown() {
    Deallocate();
}
