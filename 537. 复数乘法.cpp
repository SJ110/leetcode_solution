class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        int num1Op1 = 0,num1Op2 = 0,num2Op1 = 0,num2Op2 = 0;
        getNumber(num1,num1Op1,num1Op2);
        getNumber (num2,num2Op1,num2Op2);
        int ret1 = num1Op1 * num2Op1 - (num2Op2*num1Op2);
        int ret2 = num1Op1*num2Op2 + num1Op2*num2Op1;
        string ret = "";
        ret = to_string(ret1)+"+"+to_string(ret2)+"i";
        return ret;
    }

    void getNumber(string num, int& num1,int& num2) {
        int i = 0;
        while(i<num.size() &&(num[i]>'9' || num[i] <'0')) {
            i++;
        }
        bool islower = 0;
        if (i-1 >= 0 && num[i-1] == '-') {
            islower = 1;
        }
        string tmp = "";
        while(i<num.size() && (num[i]>= '0' && num[i]<='9')) {
            tmp = tmp + num[i];
            i++;
        }
        num1 = atoi(tmp.c_str());
        if (islower) num1 = -num1;
        while(i<num.size() &&(num[i]>'9' || num[i] <'0')) {
            i++;
        }
        if (i-1>=0 && num[i-1] == '-') {
            islower = 1;
        } else {
            islower = 0;
        }
        string tmp1 = "";
        while(i<num.size() && (num[i]>= '0' && num[i]<='9')) {
            tmp1 = tmp1 + num[i];
            i++;
        }
        num2 = atoi(tmp1.c_str());
        if (islower) num2 = -num2;
    }
};
