726. Number of Atoms
DescriptionHintsSubmissionsDiscussSolution
Discuss Pick One
Given a chemical formula (given as a string), return the count of each atom.

An atomic element always starts with an uppercase character, then zero or more lowercase letters, representing the name.

1 or more digits representing the count of that element may follow if the count is greater than 1. If the count is 1, no digits will follow. For example, H2O and H2O2 are possible, but H1O2 is impossible.

Two formulas concatenated together produce another formula. For example, H2O2He3Mg4 is also a formula.

A formula placed in parentheses, and a count (optionally added) is also a formula. For example, (H2O2) and (H2O2)3 are formulas.

Given a formula, output the count of all elements as a string in the following form: the first name (in sorted order), followed by its count (if that count is more than 1), followed by the second name (in sorted order), followed by its count (if that count is more than 1), and so on.

Example 1:
Input: 
formula = "H2O"
Output: "H2O"
Explanation: 
The count of elements are {'H': 2, 'O': 1}.
Example 2:
Input: 
formula = "Mg(OH)2"
Output: "H2MgO2"
Explanation: 
The count of elements are {'H': 2, 'Mg': 1, 'O': 2}.
Example 3:
Input: 
formula = "K4(ON(SO3)2)2"
Output: "K4N2O14S4"
Explanation: 
The count of elements are {'K': 4, 'N': 2, 'O': 14, 'S': 4}.
Note:

All atom names consist of lowercase letters, except for the first character which is uppercase.
The length of formula will be in the range [1, 1000].
formula will only consist of letters, digits, and round parentheses, and is a valid formula as defined in the problem.

class Solution {
public:
    string countOfAtoms(string formula) {
        string res, atom;
        int n=formula.size(), num;
        stack<map<string,int>> stk;
        stk.push({});
        for (int i=0, j=0; i<n; ) {
            if (isalpha(formula[i])) {
                num=0;
                j=i+1;
                while (j<n && isalpha(formula[j]) && islower(formula[j])) j++;
                atom=formula.substr(i, j-i);
                while (j<n && isdigit(formula[j])) {
                    num=num*10+formula[j]-'0';
                    j++;
                }
                stk.top()[atom]+=num==0?1:num;
                i=j;
            } else if (formula[i]=='(') {
                stk.push({});
                i++;
            } else if (formula[i]==')') {
                num=0;
                j=i+1;
                while (j<n && isdigit(formula[j])) {
                    num=num*10+formula[j]-'0';
                    j++;
                }
                if (num==0) num=1;
                auto t=stk.top();
                stk.pop();
                for (auto iter:t) {
                    stk.top()[iter.first]+=num*iter.second;
                }
                i=j;
            } else {
                i++;
            }
        }

        for (auto iter:stk.top()) {
            res+=iter.first+(iter.second>1?to_string(iter.second):"");
        }
        return res;
    }
};
