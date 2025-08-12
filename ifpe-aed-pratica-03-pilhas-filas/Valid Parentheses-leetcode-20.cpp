#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(const string &s) {
        stack<char> pilha;

        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                pilha.push(c);
            } else {
                if (pilha.empty()) return false;
                char topo = pilha.top();
                pilha.pop();

                if ((c == ')' && topo != '(') ||
                    (c == ']' && topo != '[') ||
                    (c == '}' && topo != '{')) {
                    return false;
                }
            }
        }
        return pilha.empty();
    }
};
    
int main() {
    string testes[] = { "[{()}]", "()[]{}", "{[(}])", "(][){}", "}{)(][" };
    Solution sol;

    cout << "Teste de Validação de Parênteses:\n";
    for (auto &s : testes) {
        cout << s << ": " << (sol.isValid(s) ? "Valida" : "Invalida") << endl;
    }
    return 0;
}