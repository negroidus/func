#include <iostream>
#include <vector>
#include <cassert>

// Функция, которая увеличивает все элементы вектора на n
std::vector<int> increaseVectorElements(const std::vector<int>& vec, int n) {
    std::vector<int> result(vec.size());
    for (size_t i = 0; i < vec.size(); ++i) {
        result[i] = vec[i] + n;
    }
    return result;
}

// Тест функции
void testIncreaseVectorElements() {
    // Тестовые случаи
    std::vector<std::tuple<std::vector<int>, int, std::vector<int>>> testCases = {
        {{1, 2, 3}, 2, {3, 4, 5}},
        {{-1, -2, -3}, 5, {4, 3, 2}},
        {{0, 0, 0}, 1, {1, 1, 1}},
        {{100, 200, 300}, -100, {0, 100, 200}},
        {{}, 10, {}}
    };

    for (size_t i = 0; i < testCases.size(); ++i) {
        // Распаковка кортежа для текущего теста
        const std::vector<int>& vec = std::get<0>(testCases[i]);
        int n = std::get<1>(testCases[i]);
        const std::vector<int>& expectedVec = std::get<2>(testCases[i]);

        // Вызов тестируемой функции
        std::vector<int> result = increaseVectorElements(vec, n);

        // Проверка результата
        assert(result == expectedVec && "Test failed!");
    }

    std::cout << "All tests passed." << std::endl;
}

int main() {
    // Запуск теста
    testIncreaseVectorElements();
    return 0;
}
