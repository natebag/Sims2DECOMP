struct EVec3 { float x, y, z; };

class EVec3; // Forward declaration

class ESimsCam {
public:
    void CursorMoved(int, EVec3 &);
};

// 0x80019A00 (4 bytes)
void ESimsCam::CursorMoved(int, EVec3 &) {
    // Function does nothing
}