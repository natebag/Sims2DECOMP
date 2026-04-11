struct Interactor_ESC {
    char pad[0x44];
    int m_stickMoving;
    int m_lookMoving;

    int EitherStickCentered();
};

int Interactor_ESC::EitherStickCentered() {
    int result = 0;
    if (m_stickMoving == 0 && m_lookMoving == 0) {
    } else {
        result = 1;
    }
    return result;
}
