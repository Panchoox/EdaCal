#include "eda/calculator.hpp"
#include "eda/expression_tree.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <map>

// Prompt interactivo estilo terminal
static std::string replaceVariables(const std::string& expr, const std::map<std::string,double>& vars) {
    std::istringstream iss(expr);
    std::ostringstream oss;
    std::string token;
    bool first = true;
    while (iss >> token) {
        if (!first) oss << ' ';
        first = false;
        auto it = vars.find(token);
        if (it != vars.end()) oss << it->second;
        else oss << token;
    }
    return oss.str();
}

static void printTreeIndented(const eda::ExpressionTree& tree) {
    if (tree.isEmpty()) {
        std::cout << "(empty)" << std::endl;
        return;
    }
    tree.printTree();
}

void runPrompt(eda::Calculator &calculator) {
    std::map<std::string,double> variables;
    variables["ans"] = 0.0;
    eda::ExpressionTree lastTree;

    std::string line;
    std::cout << "Bienvenido a EdaCal" << std::endl;
    while (true) {
        std::cout << ">> ";
        if (!std::getline(std::cin, line)) break;
        if (line.empty()) continue;

        auto l = line.find_first_not_of(" \t\n\r");
        if (l == std::string::npos) continue;
        auto r = line.find_last_not_of(" \t\n\r");
        std::string cmd = line.substr(l, r - l + 1);

        if (cmd == "exit") break;

        if (cmd.rfind("show ", 0) == 0) {
            std::istringstream iss(cmd);
            std::string tmp, name;
            iss >> tmp >> name;
            auto it = variables.find(name);
            if (it != variables.end()) std::cout << name << " -> " << it->second << std::endl;
            else std::cout << "Variable " << name << " no encontrada" << std::endl;
            continue;
        }

        if (cmd == "tree") { printTreeIndented(lastTree); continue; }
        if (cmd == "prefix") { std::cout << lastTree.toPrefix() << std::endl; continue; }
        if (cmd == "posfix" || cmd == "postfix") { std::cout << lastTree.toPostfix() << std::endl; continue; }

        auto eq = cmd.find('=');
        if (eq != std::string::npos) {
            std::string name = cmd.substr(0, eq);
            std::string expr = cmd.substr(eq + 1);
            auto a = name.find_first_not_of(" \t");
            auto b = name.find_last_not_of(" \t");
            if (a == std::string::npos) continue;
            name = name.substr(a, b - a + 1);
            a = expr.find_first_not_of(" \t"); if (a == std::string::npos) continue;
            b = expr.find_last_not_of(" \t"); expr = expr.substr(a, b - a + 1);

            std::string exprSub = replaceVariables(expr, variables);
                try {
                double res = calculator.evaluateInfix(exprSub);
                // Store into the named variable. Do not overwrite 'ans' on assignment
                // unless the user explicitly assigns to 'ans'.
                variables[name] = res;
                if (name == "ans") variables["ans"] = res;
                std::string post = calculator.infixToPostfix(exprSub);
                lastTree.clear(); lastTree.buildFromPostfix(post);
                std::cout << name << " -> " << res << std::endl;
            } catch (...) { std::cout << "Error al evaluar la expresión." << std::endl; }
            continue;
        }

        // Evaluación pura
        {
            std::string exprSub = replaceVariables(cmd, variables);
            try {
                double res = calculator.evaluateInfix(exprSub);
                variables["ans"] = res;
                std::string post = calculator.infixToPostfix(exprSub);
                lastTree.clear(); lastTree.buildFromPostfix(post);
                std::cout << "ans -> " << res << std::endl;
            } catch (...) { std::cout << "Error al evaluar la expresión." << std::endl; }
        }
    }
    std::cout << "¡Hasta luego!" << std::endl;
}

int main() {
    eda::Calculator calculator;
    runPrompt(calculator);
    return 0;
}
