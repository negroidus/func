#include <iostream>
#include <vector>
#include <gtest/gtest.h>

// Функция, которая увеличивает все элементы вектора на n
std::vector<int> increaseVectorElements(const std::vector<int>& vec, int n) {
    std::vector<int> result(vec.size());
    for (size_t i = 0; i < vec.size(); ++i) {
        result[i] = vec[i] + n;
    }
    return result;
}

// Тесты функции
TEST(IncreaseVectorElementsTest, HandlesPositiveIncrease) {
    std::vector<int> vec = {1, 2, 3};
    int n = 2;
    std::vector<int> expected = {3, 4, 5};
    EXPECT_EQ(increaseVectorElements(vec, n), expected);
}

TEST(IncreaseVectorElementsTest, HandlesNegativeNumbers) {
    std::vector<int> vec = {-1, -2, -3};
    int n = 5;
    std::vector<int> expected = {4, 3, 2};
    EXPECT_EQ(increaseVectorElements(vec, n), expected);
}

TEST(IncreaseVectorElementsTest, HandlesZeros) {
    std::vector<int> vec = {0, 0, 0};
    int n = 1;
    std::vector<int> expected = {1, 1, 1};
    EXPECT_EQ(increaseVectorElements(vec, n), expected);
}

TEST(IncreaseVectorElementsTest, HandlesLargeNumbers) {
    std::vector<int> vec = {100, 200, 300};
    int n = -100;
    std::vector<int> expected = {0, 100, 200};
    EXPECT_EQ(increaseVectorElements(vec, n), expected);
}

TEST(IncreaseVectorElementsTest, HandlesEmptyVector) {
    std::vector<int> vec = {};
    int n = 10;
    std::vector<int> expected = {};
    EXPECT_EQ(increaseVectorElements(vec, n), expected);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

