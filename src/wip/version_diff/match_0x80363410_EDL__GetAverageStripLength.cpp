struct EDL {
    char _pad[0x58];
    int m_numIndices;    /* 0x58 */
    int m_numStrips;     /* 0x5C */

    float GetAverageStripLength();
};

float EDL::GetAverageStripLength() {
    return (float)m_numIndices / (float)m_numStrips;
}
