#include <iostream>
#include <vector>
using namespace std;

vector<int> concatenar(const vector<int>& a, const vector<int>& b) {
    auto result = a;
    for (const auto& item: b) {
        result.push_back(item);
    }
    return result;
}

vector<int> operator+(const vector<int>& a, const vector<int>& b) {
    return concatenar(a, b);
}

ostream& imprimir(ostream& a, const vector<int>& b) {
    for(const auto& item: b) {
        a << item << " ";
    }
    return a;
}
ostream& operator<<(ostream& a,const vector<int>& b) {
    return imprimir(a, b);
}
vector<int> incrementar(vector<int>& a) {
    for (auto& item: a) {
        ++item;
    }
    return a;
}
// prefijo
vector<int> operator++(vector<int>& a) {
    return incrementar(a);
}
// subfijo
vector<int> operator++(vector<int>& a, int) {
    auto result = a;
    incrementar(a);
    return result;
}

void ejemplo1() {
    std::vector<int> v1 = {10, 20, 30};
    std::vector<int> v2 = {100, 200, 300};
    auto v3 = concatenar(v1, v2);
    auto v4 = v1 + v2;
    auto v5 = vector<int>{111, 222} + vector<int>{333, 444};
    imprimir(cout, v3) << endl;
    imprimir(cout, v4) << endl;
    cout << v3 << endl;
    cout << v4 << endl;
    cout << v5 << endl;
    cout << vector<int>{33, 44} << endl;
    ++v5;
    v5++;
    ostream& copia_cout = cout;
}

void ejemplo2() {
    vector<int> v1 = {10, 20 , 30};
    cout << ++v1 << endl;
    vector<int> v2 = {10, 20 , 30};
    cout << v2++ << endl;
    cout << v2 << endl;
}

int main() {
    ejemplo2();
    return 0;
}
