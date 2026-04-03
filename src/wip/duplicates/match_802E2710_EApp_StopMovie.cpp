struct EApp_SM {
    char pad[0x454];
    int m_movie;
    void StopMovie();
};
void EApp_SM::StopMovie() {
    m_movie = 0;
}
