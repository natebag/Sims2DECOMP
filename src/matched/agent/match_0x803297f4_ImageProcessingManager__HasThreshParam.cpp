// 0x803297f4 (24B) ImageProcessingManager::HasThreshParam(eFilter)
// Loads m_paramMask[filter], returns bit 3.
enum eFilter { eFilter_dummy };
struct ImageProcessingManager {
    static unsigned int m_paramMask[];
    static bool HasThreshParam(eFilter filter);
};
unsigned int ImageProcessingManager::m_paramMask[15];
bool ImageProcessingManager::HasThreshParam(eFilter filter) {
    return (m_paramMask[filter] >> 3) & 1;
}
