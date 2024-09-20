#include<iostream>
#include<vector>
#include<string>
#include<iomanip>
using namespace std;

class bigint{
    const int MAX_INT = 1e9;
    vector<int> num;
public:
    bigint(){
        num.push_back(0);
    }

    bigint(const bigint & bg): num(bg.num) {}
    bigint(const int x){
        num.push_back(x);
    }
    bigint &operator=(const bigint & bg) noexcept {
        if(this != &bg){
            num = bg.num;
        }
        return *this;
    }
    bigint(int &&x) noexcept  {
        num.push_back(move(x));
    }

    friend istream & operator>>(istream &in, bigint & bg){
        string s;
        in >> s;
        bg.num.clear();
        for(int i = s.size(); i >0 ; i -= 9){
            int start = i >= 9 ? i - 9: 0;
            bg.num.push_back(stoi(s.substr(start, i - start)));
        }
        return in;
    }
    friend ostream & operator<<(ostream & out , const bigint& bg){
        out << bg.num.back();
        for(int i = bg.num.size() - 2;i >= 0; --i){
            out << setw(9) << setfill('0') << bg.num[i];
            //头文件 iomanip
            //std::setw(9):这是一个用于设置输出宽度的操纵符。它将确保接下来的输出占据至少 9 个字符宽度。
            //std::setfill('0'):这是一个用于设置填充字符的操纵符。它指定如果输出的字符宽度小于指定的宽度（由 setw 设定），应该使用哪个字符来填充空位。
        }
        return out;
    }

 bigint operator+(const bigint& rhs) const {
        bigint result;
        result.num.clear();
        int carry = 0;
        size_t i = 0;

        while (i < num.size() || i < rhs.num.size() || carry) {
            int lhs_digit = (i < num.size()) ? num[i] : 0;
            int rhs_digit = (i < rhs.num.size()) ? rhs.num[i] : 0;
            int sum = lhs_digit + rhs_digit + carry;
            result.num.push_back(sum % MAX_INT);
            carry = sum / MAX_INT;
            ++i;
        }

        return result;
    }

    // 运算符重载：减法
    bigint operator-(const bigint& rhs) const {
        // 此处简化为假设 lhs >= rhs
        bigint result;
        result.num.clear();
        int borrow = 0;
        size_t i = 0;

        while (i < num.size() || i < rhs.num.size()) {
            int lhs_digit = (i < num.size()) ? num[i] : 0;
            int rhs_digit = (i < rhs.num.size()) ? rhs.num[i] : 0;
            int diff = lhs_digit - rhs_digit - borrow;
            if (diff < 0) {
                diff += MAX_INT;
                borrow = 1;
            } else {
                borrow = 0;
            }
            result.num.push_back(diff);
            ++i;
        }

        return result;
    }

    // 运算符重载：乘法
    bigint operator*(const bigint& rhs) const {
        bigint result;
        result.num = std::vector<int>(num.size() + rhs.num.size(), 0);

        for (size_t i = 0; i < num.size(); ++i) {
            long long carry = 0;
            for (size_t j = 0; j < rhs.num.size() || carry; ++j) {
                long long mul = result.num[i + j] + carry + 1LL * num[i] * (j < rhs.num.size() ? rhs.num[j] : 0);
                result.num[i + j] = mul % MAX_INT;
                carry = mul / MAX_INT;
            }
        }
        while(result.num.back() == 0){
            result.num.pop_back();
        }
        return result;
    }

    // 比较运算符：等于
    bool operator==(const bigint& rhs) const {
        return num == rhs.num;
    }

    // 比较运算符：小于
    bool operator<(const bigint& rhs) const {
        if (num.size() != rhs.num.size()) {
            return num.size() < rhs.num.size();
        }
        for (size_t i = num.size(); i-- > 0;) {
            if (num[i] != rhs.num[i]) {
                return num[i] < rhs.num[i];
            }
        }
        return false;
    }

    // 比较运算符：大于
    bool operator>(const bigint& rhs) const {
        return rhs < *this;
    }



};


int main(){
    bigint x;
    cin >> x;
    x = x * x;
    cout << x;
    return 0;

}