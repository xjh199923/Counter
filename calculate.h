#include "stack.h"
#include <vector>
#include<stdlib.h>
#include <math.h>
#include<algorithm>
string format(string str){
	for(int i = 0;i < str.length(); i++){
		if(str[i] == '-')
		{
			if(i == 0){
				str.insert(0,1,'0');
			}
			else if(str[i-1] == '('){
				str.insert(i,1,'0');
			}
		}
		
	}
	return str;
}
bool isMark(char ch)
{
	switch(ch)
	{
		case '+':
			return 1;
			break;
		case '-':
			return 1;
			break;
		case '*':
			return 1;
			break;
		case '/':
			return 1;
			break;
		case '%':
			return 1;
			break;
		case '(':
			return 1;
			break;
		case '^':
			return 1;
			break;
		default:
			return 0;
	}
}
int prior(char op){//求运算符优先级
	switch (op) {
		case '#':
			return -1;
			break;
		case '(':
			return 0;
			break;
		case '+':
			return 1;
			break;
		case '-':
			return 1;
			break;
		case '*':
			return 2;
			break;
		case '/':
			return 2;
			break;
		case '%':
			return 2;
			break;
		case '^':
			return 3;
			break;
		default:
			return -1;
	}
}
//中缀表达式转后缀表达式
vector<string> convert(string input){
	
		Stack<char> stk;//存储操作符栈
		vector<string> temp;
		char s;
		string tmp = "";	
		int length = (int)input.length();//获取表达式的长度
		for(int i = 0; i < length; i++){
			tmp = "";
			
			if((input[i]>='0' && input[i]<='9')){
				tmp += input[i];
				while((i+1<input.size() && input[i+1]>='0' && input[i+1]<='9')||input[i+1] == '.')
				{
						tmp += input[i+1];//若是连续数字
						++i;
				}
				temp.push_back(tmp);
			}
			else if(input[i] == '('){
				//遇到左括号直接入栈
				stk.Push(input[i]);
			}
			else if(input[i] == ')'){
				//如果遇到右括号的话，就把一直到最近的左括号之间的都弹出来加入temp中
				while(stk.getTopelements() != '('){
					tmp += stk.getTopelements();
					temp.push_back(tmp);
					stk.Pop(s);
					tmp="";
				}
				stk.Pop(s);//把左括号弹出栈
			}
			else if(isMark(input[i])){
				//如果是运算符的话，比较他们的优先级再决定是否入栈
				while( prior(input[i])<=prior(stk.getTopelements()) ){
					//如果当前的优先级小于等于栈顶操作符的话，栈顶操作符弹出，加入temp
					tmp += stk.getTopelements();
					temp.push_back(tmp);
					stk.Pop(s);
					tmp="";
				}
				//如果当前的优先级大于栈顶操作符的话，入栈
				stk.Push(input[i]);
			}
		}
		//如果已经扫描到中缀表达式的末尾，就把栈中的操作符都弹出来加入到temp中
		while(!stk.isEmpty()){
			tmp="";
			tmp += stk.getTopelements();
			temp.push_back(tmp);
			stk.Pop(s);
			tmp="";
		}
	return temp;
}
//计算后缀表达式的最终数值
double calculate(vector<string> retu){
	
	int i = 0;
	Stack<double> optNum;//定义一个操作数栈
	double s;
	
	double x1,x2 = 0;
	double num;
	
	for(int i = 0;i < retu.size(); i++){//没有遇到结束标志#，即进行表达式的计算
	
	    string tmp = retu[i];
		if(tmp[0] >= '0'&&tmp[0] <= '9'){
			num = atof(tmp.c_str());
			optNum.Push(num);
		}
			else if(retu[i] == "+"){
			x1 = optNum.getTopelements();
			optNum.Pop(s);
			x2 = optNum.getTopelements();
			optNum.Pop(s);
			optNum.Push(x1+x2);
		}
		
		else if(retu[i] == "-"){
			x1 = optNum.getTopelements();
			optNum.Pop(s);
			x2 = optNum.getTopelements();
			optNum.Pop(s);
			optNum.Push(x2-x1);
		}
		
		else if(retu[i] == "*"){
			x1 = optNum.getTopelements();
			optNum.Pop(s);
			x2 = optNum.getTopelements();
			optNum.Pop(s);
			optNum.Push(x1*x2);
		}
		
		else if(retu[i] == "/"){
			x1 = optNum.getTopelements();
			optNum.Pop(s);
			x2 = optNum.getTopelements();
			optNum.Pop(s);
			optNum.Push(x2/x1);
		}
		else if(retu[i] == "%"){
			x1 = optNum.getTopelements();
			optNum.Pop(s);
			x2 = optNum.getTopelements();
			optNum.Pop(s);
			optNum.Push((int)x2%(int)x1);
		}
		else if(retu[i] == "^"){
			x1 = optNum.getTopelements();
			optNum.Pop(s);
			x2 = optNum.getTopelements();
			optNum.Pop(s);
			optNum.Push(pow(x2, x1));
		}
	}
	
	return optNum.getTopelements();//返回最终的计算结果
}
double result(string str){
	str = format(str);
	vector<string> bh = convert(str);
	double k = calculate(bh);
	return k;	
}
