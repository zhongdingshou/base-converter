#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//top全局变量表示栈顶元素所在的位置
int top = -1;

//将元素element推入栈内
void push(char * stack, char element){
    stack[++top] = element;
}

//将元素从栈输出 
void pop(char * stack){
    if (top == -1) {//栈为空 
        return;
    }
    //元素按照正确的格式输出到屏幕
    if (stack[top] >= 10) {
        printf("%c", stack[top] + 55);
    }else{
        printf("%d", stack[top]);
    }
    top--;
}

//将各进制数数据转换成十进制数的 
int Transformation(char * data, int in){
    int k = (int)strlen(data) - 1;//获取字符串数据长度，并强制转换为整型 
    int decimal = 0, i;
    for (i = k; i >= 0; i--) {
        int temp;	//用于临时存放
        if (data[i] >= 48 && data[i] <= 57) {
            temp = data[i] - 48;
        }else{
            temp = data[i] - 55;
        }
        decimal += temp * pow(in, k - i);//double pow(double x, double y); 函数用来求 x 的 y 次方的值。
    }
    return decimal;
}

//主函数 
int main(int argc, char *argv[]) {
	
    printf("\t进制转换器\n请输入原始数据的进制（2-36）:");
    int in;//进制数 
    scanf("%d", &in);
    fflush(stdin);//清空输入缓冲区
    if(in < 2 || in > 36){//进制数不符合 
    	printf("进制数不符合\n");
  		return 0;
   	}
   	
    printf("请输入原始数据值：");
    char data[100];
    scanf("%s", data);
    fflush(stdin);
    
    int decimal = Transformation(data, in);//先转成十进制 
    int newIn;//输出的进制数 
    
    printf("请输入想要转成几进制？（2-36）：");
	scanf("%d", &newIn);
 	fflush(stdin);
 	if(newIn < 2 || newIn > 36){//进制数不符合 
    	printf("进制数不符合\n");
  		return 0;
   	}
 	
	while (decimal / newIn) {
   		push(data, decimal % newIn );//数据进栈 
   		decimal /= newIn;
	}
   	push(data, decimal % newIn);//数据进栈 
   	
   	printf("转换后的结果为：");
   	while (top != -1) {//将栈内元素全部输出
   		pop(data);
   	}
   	
   	printf("\n");
	system("pause");
    return 0; 
}
