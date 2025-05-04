struct Solution
{
    static constexpr int numEquivDominoPairs(
            std::span<const std::vector<int>> dominoes) noexcept
    {
        std::array<int, 100> counter = {};
        for (auto& domino: dominoes)
        {
            const int normalized = (domino[0] < domino[1])
                    ? domino[0] * 10 + domino[1]
                    : domino[1] * 10 + domino[0];
            ++counter[normalized];
        }
        return std::accumulate(
                begin(counter), end(counter), 0,
                [](auto acc, auto count) {
                    return acc + count * (count - 1) / 2;
                });
    }
};