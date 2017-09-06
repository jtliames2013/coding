341. Flatten Nested List Iterator
Given a nested list of integers, implement an iterator to flatten it.

Each element is either an integer, or a list -- whose elements may also be integers or other lists.

Example 1:
Given the list [[1,1],2,[1,1]],

By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,1,2,1,1].

Example 2:
Given the list [1,[4,[6]]],

By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,4,6]. 

Note: Flatten the nested list into a vector using recursion.

1. Use stack
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
public:
    void tryAdvance() {
        while (!stk.empty()) {
            if (stk.top().isInteger()) break;
            else {
                NestedInteger t=stk.top();
                stk.pop();
                vector<NestedInteger> v=t.getList();
                for (int i=v.size()-1; i>=0; i--) stk.push(v[i]);
            }
        }
    }
    
    NestedIterator(vector<NestedInteger> &nestedList) {
        for (int i=nestedList.size()-1; i>=0; i--) stk.push(nestedList[i]);
        tryAdvance();
    }

    int next() {
        int res=stk.top().getInteger();
        stk.pop();
        tryAdvance();
        return res;
    }

    bool hasNext() {
        return !stk.empty();
    }
private:
    stack<NestedInteger> stk;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */

2. Use begin and end iterator to keep track each list level
class NestedIterator {
public:
    void tryAdvance() {
        while (!begin.empty()) {
            if (begin.top()==end.top()) {
                begin.pop();
                end.pop();
            } else {
                if (begin.top()->isInteger()) break;
                else {
                    auto t=begin.top();
                    begin.top()++;
                    begin.push(t->getList().begin());
                    end.push(t->getList().end());
                }
            }
        }
    }
    
    NestedIterator(vector<NestedInteger> &nestedList) {
        begin.push(nestedList.begin());
        end.push(nestedList.end());
        tryAdvance();
    }

    int next() {
        if (!hasNext()) return -1;
        int res=begin.top()->getInteger();
        begin.top()++;
        tryAdvance();
        return res;
    }

    bool hasNext() {
        return !begin.empty();
    }
private:
    stack<vector<NestedInteger>::iterator> begin, end;
};

