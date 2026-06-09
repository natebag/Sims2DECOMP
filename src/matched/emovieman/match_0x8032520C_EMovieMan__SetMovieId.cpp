struct EMovieMan {
    char _pad[0xd20];
    unsigned int m_movieId;
    void SetMovieId(unsigned int val);
};
void EMovieMan::SetMovieId(unsigned int val) { m_movieId = val; }
