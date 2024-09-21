#include <iostream>
#include <vector>
#include <string>

// 计算前缀表
std::vector<int> computePrefix(const std::string& pattern) {
    int m = pattern.size();
    std::vector<int> prefix(m, 0);
    int k = 0;
    for (int i = 1; i < m; ++i) {
        while (k > 0 && pattern[k] != pattern[i]) {
            k = prefix[k - 1];
        }
        if (pattern[k] == pattern[i]) {
            ++k;
        }
        prefix[i] = k;
    }
    return prefix;
}

// KMP 算法
std::vector<int> kmpSearch(const std::string& text, const std::string& pattern) {
    std::vector<int> prefix = computePrefix(pattern);
    std::vector<int> result;
    int n = text.size();
    int m = pattern.size();
    int q = 0; // 当前已匹配的字符数
    for (int i = 0; i < n; ++i) {
        while (q > 0 && pattern[q] != text[i]) {
            q = prefix[q - 1]; // 使用前缀表跳转
        }
        if (pattern[q] == text[i]) {
            ++q;
        }
        if (q == m) {
            result.push_back(i - m + 1); // 匹配成功，记录下标
            q = prefix[q - 1];
        }
    }
    return result;
}

int main() {
    std::string text = "ababcabcabababa";
    std::string pattern = "ababa";
    std::vector<int> matches = kmpSearch(text, pattern);
    
    if (!matches.empty()) {
        std::cout << "Pattern found at indices: ";
        for (int index : matches) {
            std::cout << index << " ";
        }
        std::cout << std::endl;
    } else {
        std::cout << "Pattern not found." << std::endl;
    }
    
    return 0;
}
