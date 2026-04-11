/* 0x80303CCC (24 bytes) - CheatMenuParams::CheatMenuParams(void) */
class EDebugMenuItem;
class CheatMenuParams {
public:
    EDebugMenuItem *m_first;
    EDebugMenuItem *m_last;
    int m_count;
    CheatMenuParams();
};
CheatMenuParams::CheatMenuParams() { m_first = 0; m_last = 0; m_count = 0; }
