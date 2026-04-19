/* InteractorModule::InteractorManager::IsValidPlayerId(int) const at 0x8020BDBC (56B) */
/* VERSION_DIFF: SN ProDG backward-branch shared-return pattern.
 * DOL places li r3,0/blr at offset 8, then all 3 bound checks branch BACKWARD to
 * that shared false-return block. GCC emits forward branches with return-false at
 * end. No standard C++ form forces GCC to place the exit block before the checks.
 */

struct InteractorMgr_IVPI {
    void* m_data;        // 0
    int m_maxPlayers;    // 4
    bool IsValidPlayerId(int playerId) const;
};

bool InteractorMgr_IVPI::IsValidPlayerId(int playerId) const {
    if (!m_data) return false;
    if (playerId < 0) return false;
    if (playerId >= m_maxPlayers) return false;
    if (playerId > 7) return false;
    return true;
}
