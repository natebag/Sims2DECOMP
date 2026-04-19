/* ENgcController::IsMotorTwoActive(void) at 0x803C7254 (32B) */
// 0x803C7254 (32 bytes)
class EController {
public:
    bool IsMotorTwoActive() const;
};
class ENgcController : public EController {
public:
    bool IsMotorTwoActive() const;
};
bool ENgcController::IsMotorTwoActive() const {
    return EController::IsMotorTwoActive();
}
