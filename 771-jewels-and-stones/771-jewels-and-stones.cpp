class Solution {
public:
    int numJewelsInStones(std::string jewels, std::string stones) 
    {
        size_t counter = 0;
        for (char &element : jewels)
        {
            counter += std::count(stones.begin(), stones.end(), element);
        }

        return counter;

    }
};