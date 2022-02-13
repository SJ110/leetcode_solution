/// 逆波兰式求值
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 返回表达式的值
     * @param s string字符串 待计算的表达式
     * @return int整型
     */
    int getPriority (string &s) {
        if(s == "*") {
            return 2;
        } else if(s == "+" || s == "-") {
            return 1;
        }
        return 0;
    }
    
    int makeCount (string &s,int a,int b) {
        if(s == "+") {
            return a+b;
        } else if(s == "-") {
            return b-a;
        } else if(s == "*") {
            return a*b;
        }
        return 0;
    }
    
    int solve(string s) {
        // write code here
        stack<string> symbol;
        stack<string> numbers;
        int idx = 0;
        while(idx <s.length()) {
            if(s[idx] >= '0' && s[idx]<= '9') {
                string tmp = "";
                while(idx>=0 && s[idx]>='0' && s[idx]<='9') {
                    tmp = tmp+s[idx];
                    idx++;
                }
                numbers.push(tmp);
            } else if(s[idx] == '*' || s[idx] == '+' || s[idx] == '-') {
                string tmp = "";
                tmp.append(1,s[idx]);
                while(true) {
                    if(symbol.empty() || symbol.top() == "(") {
                        symbol.push(tmp);
                        break;
                    } else {
                        if(getPriority(tmp)>getPriority(symbol.top())) {
                            symbol.push(tmp);
                            break;
                        } else {
                            if(!symbol.empty()) {
                                numbers.push(symbol.top());
                                symbol.pop();
                            }
                        }
                    }
                }
                idx++;
            } else {
                if(s[idx] == '(') {
                    string tmp = "";
                    tmp.append(1,s[idx]);
                    symbol.push(tmp);
                } else {
                    /// 是右括号 (
                    while(!symbol.empty()) {
                        string tmp = symbol.top();
                        symbol.pop();
                        if(tmp == "(") {
                            break;
                        } else {
                            numbers.push(tmp);
                        }
                    }
                }
                idx++;
            }
        }
        while(!symbol.empty()) {
            numbers.push(symbol.top());
            symbol.pop();
        }
        stack<string> helper;
        while(!numbers.empty()) {
            helper.push(numbers.top());
            numbers.pop();
        }
        while(!helper.empty()) {
            if(helper.top() == "+" || helper.top() == "-" || helper.top() == "*") {
                int num1 = stoi(numbers.top());
                numbers.pop();
                int num2 = stoi(numbers.top());
                numbers.pop();
                int cnt = makeCount(helper.top(), num1, num2);
                numbers.push(to_string(cnt));
                helper.pop();
            } else {
                numbers.push(helper.top());
                helper.pop();
            }
        }
        int ret = stoi(numbers.top());
        return ret;
    }
};
