// 0x803297dc (24B) ImageProcessingManager::HasHSVParam(eFilter)
// Loads m_paramMask[filter], returns bit 2.
enum eFilter { eFilter_dummy };
struct ImageProcessingManager {
    static unsigned int m_paramMask[];
    static bool HasHSVParam(eFilter filter);
};
unsigned int ImageProcessingManager::m_paramMask[15];
bool ImageProcessingManager::HasHSVParam(eFilter filter) {
    return (m_paramMask[filter] >> 2) & 1;
}
