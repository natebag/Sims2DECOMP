/* ENgcController::IsMotorOneActive(void) at 0x803C7234 (32B) */
// 0x803C7234 (32 bytes)
class EController {
public:
    bool IsMotorOneActive() const;
};
class ENgcController : public EController {
public:
    bool IsMotorOneActive() const;
};
bool ENgcController::IsMotorOneActive() const {
    return EController::IsMotorOneActive();
}
