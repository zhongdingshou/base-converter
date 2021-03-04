#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//topȫ�ֱ�����ʾջ��Ԫ�����ڵ�λ��
int top = -1;

//��Ԫ��element����ջ��
void push(char * stack, char element){
    stack[++top] = element;
}

//��Ԫ�ش�ջ��� 
void pop(char * stack){
    if (top == -1) {//ջΪ�� 
        return;
    }
    //Ԫ�ذ�����ȷ�ĸ�ʽ�������Ļ
    if (stack[top] >= 10) {
        printf("%c", stack[top] + 55);
    }else{
        printf("%d", stack[top]);
    }
    top--;
}

//��������������ת����ʮ�������� 
int Transformation(char * data, int in){
    int k = (int)strlen(data) - 1;//��ȡ�ַ������ݳ��ȣ���ǿ��ת��Ϊ���� 
    int decimal = 0, i;
    for (i = k; i >= 0; i--) {
        int temp;	//������ʱ���
        if (data[i] >= 48 && data[i] <= 57) {
            temp = data[i] - 48;
        }else{
            temp = data[i] - 55;
        }
        decimal += temp * pow(in, k - i);//double pow(double x, double y); ���������� x �� y �η���ֵ��
    }
    return decimal;
}

//������ 
int main(int argc, char *argv[]) {
	
    printf("\t����ת����\n������ԭʼ���ݵĽ��ƣ�2-36��:");
    int in;//������ 
    scanf("%d", &in);
    fflush(stdin);//������뻺����
    if(in < 2 || in > 36){//������������ 
    	printf("������������\n");
  		return 0;
   	}
   	
    printf("������ԭʼ����ֵ��");
    char data[100];
    scanf("%s", data);
    fflush(stdin);
    
    int decimal = Transformation(data, in);//��ת��ʮ���� 
    int newIn;//����Ľ����� 
    
    printf("��������Ҫת�ɼ����ƣ���2-36����");
	scanf("%d", &newIn);
 	fflush(stdin);
 	if(newIn < 2 || newIn > 36){//������������ 
    	printf("������������\n");
  		return 0;
   	}
 	
	while (decimal / newIn) {
   		push(data, decimal % newIn );//���ݽ�ջ 
   		decimal /= newIn;
	}
   	push(data, decimal % newIn);//���ݽ�ջ 
   	
   	printf("ת����Ľ��Ϊ��");
   	while (top != -1) {//��ջ��Ԫ��ȫ�����
   		pop(data);
   	}
   	
   	printf("\n");
	system("pause");
    return 0; 
}
