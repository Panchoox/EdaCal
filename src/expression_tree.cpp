#include "eda/expression_tree.hpp"
#include <sstream>
#include <stack>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

namespace eda {

TreeNode::TreeNode() : value(""), left(nullptr), right(nullptr) {
}

TreeNode::TreeNode(const std::string& value) : value(value), left(nullptr), right(nullptr) {
}

TreeNode::~TreeNode() {
}

std::string TreeNode::getValue() const {
    return value;
}

void TreeNode::setValue(const std::string& value) {
    this->value = value;
}

TreeNode* TreeNode::getLeft() const {
    return left;
}

void TreeNode::setLeft(TreeNode* left) {
    this->left = left;
}

TreeNode* TreeNode::getRight() const {
    return right;
}

void TreeNode::setRight(TreeNode* right) {
    this->right = right;
}

ExpressionTree::ExpressionTree() : root(nullptr) {
}

ExpressionTree::~ExpressionTree() {
    clear();
}

void ExpressionTree::buildFromPostfix(const std::string& expression) {
    clear();
    if (expression.empty()) return;

    istringstream iss(expression);
    string token;
    stack<TreeNode*> st;

    while (iss >> token) {
        if (token == "sqrt") {
            if (st.empty()) {
                clear();
                return;
            }
            TreeNode* operand = st.top(); st.pop();
            TreeNode* node = new TreeNode("sqrt");
            node->setLeft(operand);
            node->setRight(nullptr);
            st.push(node);
        } else if (token == "+" || token == "-" || token == "*" || token == "/" || token == "^") {
            if (st.size() < 2) {
                clear();
                return;
            }
            TreeNode* right = st.top(); st.pop();
            TreeNode* left = st.top(); st.pop();
            TreeNode* node = new TreeNode(token);
            node->setLeft(left);
            node->setRight(right);
            st.push(node);
        } else {
            TreeNode* node = new TreeNode(token);
            node->setLeft(nullptr);
            node->setRight(nullptr);
            st.push(node);
        }
    }

    if (st.empty()) {
        root = nullptr;
        return;
    }

    root = st.top(); st.pop();
    while (!st.empty()) {
        clearHelper(st.top());
        st.pop();
    }
}

void ExpressionTree::buildFromPrefix(const std::string& expression) {
    if (expression.empty()) return;
    istringstream iss(expression);
    vector<string> toks;
    string t;
    while (iss >> t) toks.push_back(t);

    stack<string> st;
    for (auto it = toks.rbegin(); it != toks.rend(); ++it) {
        const string& token = *it;
        if (token == "+" || token == "-" || token == "*" || token == "/" || token == "^" || token == "sqrt") {
            if (token == "sqrt") {
                if (st.empty()) return;
                string a = st.top(); st.pop();
                string expr = a + " " + token;
                st.push(expr);
            } else {
                if (st.size() < 2) return;
                string a = st.top(); st.pop();
                string b = st.top(); st.pop();
                string expr = a + " " + b + " " + token;
                st.push(expr);
            }
        } else {
            st.push(token);
        }
    }

    if (st.empty()) return;
    string postfix = st.top();
    buildFromPostfix(postfix);
}

void ExpressionTree::buildFromInfix(const std::string& expression) {
    if (expression.empty()) return;
    istringstream iss(expression);
    vector<string> output;
    stack<string> ops;
    string token;

    auto precedence = [](const string& op)->int {
        if (op == "^") return 4;
        if (op == "*" || op == "/") return 3;
        if (op == "+" || op == "-") return 2;
        if (op == "sqrt") return 5;
        return 0;
    };

    while (iss >> token) {
        if (token == "(") {
            ops.push(token);
        } else if (token == ")") {
            while (!ops.empty() && ops.top() != "(") {
                output.push_back(ops.top()); ops.pop();
            }
            if (!ops.empty() && ops.top() == "(") ops.pop();
        } else if (token == "+" || token == "-" || token == "*" || token == "/" || token == "^" || token == "sqrt") {
            while (!ops.empty()) {
                string top = ops.top();
                if ((precedence(top) > precedence(token)) || (precedence(top) == precedence(token) && token != "^")) {
                    if (top == "(") break;
                    output.push_back(top); ops.pop();
                    continue;
                }
                break;
            }
            ops.push(token);
        } else {
            output.push_back(token);
        }
    }

    while (!ops.empty()) { output.push_back(ops.top()); ops.pop(); }

    ostringstream oss;
    for (size_t i = 0; i < output.size(); ++i) {
        if (i) oss << ' ';
        oss << output[i];
    }
    buildFromPostfix(oss.str());
}

double ExpressionTree::evaluate() const {
    return evaluateHelper(root);
}

std::string ExpressionTree::toInfix() const {
    return toInfixHelper(root);
}

std::string ExpressionTree::toPrefix() const {
    return toPrefixHelper(root);
}

std::string ExpressionTree::toPostfix() const {
    return toPostfixHelper(root);
}

bool ExpressionTree::isEmpty() const { return root == nullptr; }

void ExpressionTree::clear() {
    clearHelper(root);
    root = nullptr;
}


void ExpressionTree::clearHelper(TreeNode* node) {
    if (!node) return;
    clearHelper(node->getLeft());
    clearHelper(node->getRight());
    delete node;
}

double ExpressionTree::evaluateHelper(TreeNode* node) const {
    if (!node) return 0.0;
    string val = node->getValue();
    if (val == "+" || val == "-" || val == "*" || val == "/" || val == "^") {
        double l = evaluateHelper(node->getLeft());
        double r = evaluateHelper(node->getRight());
        if (val == "+") return l + r;
        if (val == "-") return l - r;
        if (val == "*") return l * r;
        if (val == "/") return l / r;
        if (val == "^") return pow(l, r);
    } else if (val == "sqrt") {
        double l = evaluateHelper(node->getLeft());
        return sqrt(l);
    } else {
        try { return stod(val); } catch (...) { return 0.0; }
    }
    return 0.0;
}

std::string ExpressionTree::toInfixHelper(TreeNode* node) const {
    if (!node) return "";
    string val = node->getValue();
    if (!node->getLeft() && !node->getRight()) return val;
    if (val == "sqrt") {
        return string("sqrt(") + toInfixHelper(node->getLeft()) + ")";
    }
    return string("(") + toInfixHelper(node->getLeft()) + " " + val + " " + toInfixHelper(node->getRight()) + ")";
}

std::string ExpressionTree::toPrefixHelper(TreeNode* node) const {
    if (!node) return "";
    string val = node->getValue();
    if (!node->getLeft() && !node->getRight()) return val;
    if (val == "sqrt") return string("sqrt ") + toPrefixHelper(node->getLeft());
    return val + string(" ") + toPrefixHelper(node->getLeft()) + string(" ") + toPrefixHelper(node->getRight());
}

std::string ExpressionTree::toPostfixHelper(TreeNode* node) const {
    if (!node) return "";
    string val = node->getValue();
    if (!node->getLeft() && !node->getRight()) return val;
    if (val == "sqrt") return toPostfixHelper(node->getLeft()) + string(" sqrt");
    return toPostfixHelper(node->getLeft()) + string(" ") + toPostfixHelper(node->getRight()) + string(" ") + val;
}

void ExpressionTree::printTree() const {
    if (!root) {
        std::cout << "(empty)" << std::endl;
        return;
    }
    std::function<void(TreeNode*, const std::string&, bool)> recurse;
    recurse = [&](TreeNode* node, const std::string& prefix, bool isLeft) {
        if (!node) return;
    std::cout << prefix;
    std::cout << (isLeft ? "├── " : "└── ");
        std::cout << node->getValue() << std::endl;
        std::string childPrefix = prefix + (isLeft ? "│   " : "    ");
        if (node->getLeft()) recurse(node->getLeft(), childPrefix, true);
        if (node->getRight()) recurse(node->getRight(), childPrefix, false);
    };
    std::cout << root->getValue() << std::endl;
    if (root->getLeft()) recurse(root->getLeft(), std::string(), true);
    if (root->getRight()) recurse(root->getRight(), std::string(), false);
}

void ExpressionTree::printTreeHelper(TreeNode* node, int depth) const {
    if (!node) return;
    for (int i = 0; i < depth; ++i) std::cout << "  ";
    std::cout << node->getValue() << std::endl;
    if (node->getLeft()) printTreeHelper(node->getLeft(), depth + 1);
    if (node->getRight()) printTreeHelper(node->getRight(), depth + 1);
}

} // namespace eda
