/*
����������ʵ��ͣ��������ϵͳ
ʹ��ջ�Ĵ洢���ʾ��������ͣ����
ʹ�ö��б�ʾͣ������ı���ϳ������
���ߣ�William
*/
#include<stdio.h>
#include<stdlib.h>
#include<string>
#define N 5//NΪͣ����������С
typedef struct//�ṹ��ָ���ʾÿһ��ͣ�����ĳ������
{
	char Numb[6];//���ƺ���
	int Time[4];//����ͣ������ʱ��
}Rec;
typedef Rec *RecPointer;

typedef struct//ͣ�����������
{
	RecPointer base;
	RecPointer top;
	int stacksize;
}SqStack;//SqStack  S

int InitStack(SqStack &S)//ջ��ͣ�������ĳ�ʼ��
{
	S.base = (RecPointer)malloc(N * sizeof(Rec));
	if (!S.base)
		exit(-1);
	S.top = S.base;
	S.stacksize = N;
	return 1;
}

int Pop(SqStack &S, char *e, int T[])//��ջ��ͣ������
{
	if (S.top == S.base)
		return 0;
	else
	{
		S.top--;//topָ������һλ��ָ�򶥲�Ԫ��
		strcpy(e, S.top->Numb);
		T[0] = S.top->Time[0];
		T[1] = S.top->Time[1];
		T[2] = S.top->Time[2];
		T[3] = S.top->Time[3];
		return 1;
	}
}

int TravelS(SqStack S)//����ջ��ͣ������
{
	RecPointer p;
	int i = 1;
	p = S.base;
	if (S.base == S.top)
		return 0;
	while (p != S.top)
	{
		printf("********************************************\n");
		printf("%d��ͣ��λ����ͣ������������Ϊ%s���볡ʱ��Ϊ%d��%d��%d��%d��         *\n", i, p->Numb, p->Time[0], p->Time[1], p->Time[2], p->Time[3]);
		i++;
		p++;
	}
	while (i <= N)
	{
		printf("********************************************\n");
		printf("%d��ͣ��λ��δͣ��                          *\n", i);
		i++;
	}
	printf("********************************************\n");
	return 1;
}

int Push(SqStack &S, char *e1, int T1[])//��ջ��ͣ������
{
	if (S.top - S.base >= N)//ͣ��������
		return 0;
	strcpy(S.top->Numb, e1);//���ƺ�
	S.top->Time[0] = T1[0];//�볡ʱ��
	S.top->Time[1] = T1[1];
	S.top->Time[2] = T1[2];
	S.top->Time[3] = T1[3];
	S.top++;
	return 1;
}

typedef struct QNode//���У����������
{
	char data[5];//���泵�ƺ�
	struct QNode *next;
}QNode, *QueuePtr;

typedef struct
{
	QueuePtr front;//����ͷ��
	QueuePtr rear;//����β��
}LinkQueue;

int InitQueue(LinkQueue *Q)//���У��������ʼ��
{
	Q->front = Q->rear = (QueuePtr)malloc(sizeof(QNode));//����һ�����Ŀռ�
	if (!(Q->front))
		exit(1);
	Q->front->next = 0;//��ʼ��ָ��
}

void EnQueue(LinkQueue *Q, char *e3)//���У�������������
{
	QueuePtr p;
	p = (QueuePtr)malloc(sizeof(QNode));
	if (!p)
		exit(1);
	strcpy(p->data, e3);
	p->next = 0;
	Q->rear->next = p;//β��ָ������p
	Q->rear = p;//p��Ϊ�µ�β��ָ��
}

int TravelQ(LinkQueue *Q)//���У����������
{
	QNode *p;
	int i = 1;
	if (Q->front == Q->rear)//����Ϊ��
		return 0;
	p = Q->front->next;
	while (p != Q->rear)//Q��βָ��洢�����ݣ������������βָ�������
	{
		printf("���%d��λ����ͣ������������Ϊ%s         *\n", i, p->data);
		printf("********************************************\n");
		p = p->next;
		i++;
	}
	printf("���%d��λ����ͣ������������Ϊ%s         *\n", i, p->data);//��βָ�����ݽ������
	printf("********************************************\n");
	return 1;
}

int DeQueue(LinkQueue *Q, char *e4)//�����У������
{
	QNode *p;
	if (Q->front == Q->rear)
		return 0;
	p = Q->front->next;
	strcpy(e4, p->data);
	Q->front->next = p->next;//��ͷָ��δ�洢����
	if (Q->rear == p)
		Q->rear = Q->front;
	free(p);
	return 1;
}

int  DayofYear(int year, int month, int day) {
	int i, mm, days = 0;
	int a[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	/*�ж��Ƿ�Ϊ����*/
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
	{
		mm = 1;
	}
	else
	{
		mm = 0;
	}

	/*���Ϊ���꣬��ı���·ݵ�����*/
	if (mm == 1)
	{
		a[1] = 29;
	}

	/*��Ϊ�����һ������0��ʼ������month-1���±���������Ϊmonth-2*/
	for (i = month - 2;i >= 0;i--)
	{
		days += day;
		days += a[i];
	}
	return days;
}

int Coming_Car(SqStack &S, LinkQueue *Q, char *Num, int Time1[])
{
	if (!(Push(S, Num, Time1)))//ͣ��������,������
	{
		Time1[0] = 0;
		Time1[1] = 0;
		Time1[2] = 0;
		Time1[3] = 0;
		EnQueue(Q, Num);
		printf("********************************************\n");
		printf("ͣ����������������                       *\n");
		printf("********************************************\n");
	}
	else
	{
		printf("********************************************\n");
		printf("���ƺ�Ϊ%s�ĳ�����ͣ������ͣ��%d�ų�λ���볡ʱ��Ϊ%d��%d��%d��%d��   *\n", Num, S.top - S.base, Time1[0], Time1[1], Time1[2], Time1[3]);
		printf("********************************************\n");
	}
	return 1;
}

int Leaving_Car(SqStack &S, LinkQueue *Q, int Loc, int Time2[])
{
	int Y, M, D, H, Charge;
	int D1;
	int DL, DC;
	DL = DayofYear(Time2[0], Time2[1], Time2[2]);
	RecPointer p;
	int i;
	p = S.base;
	for (i = 1;i < Loc;i++)//�ҵ���ͣ�����ĳ�����λ�ã������ж�ʱ�������Ƿ���ȷ��
		p++;
	DC = DayofYear(p->Time[0], p->Time[1], p->Time[2]);
	if (Time2[0] < p->Time[0])
	{
		printf("�뿪ʱ������");
		return 0;
	}
	else if (Time2[0] > p->Time[0])//����뿪ʱ��ݶ������볡ʱ��
	{
		Y = Time2[0] - p->Time[0];
		if (Time2[1] < p->Time[1])
		{
			Y--;
			M = Time2[1] + 12 - p->Time[1];
			D = Time2[2] - p->Time[2] + M * 30;
			if (Time2[3] >= p->Time[3])
				H = Time2[3] - p->Time[3];
			else
			{
				H = Time2[3] + 24 - p->Time[3];
				D--;
			}
		}
		else if (Time2[3] >= p->Time[3])//Сʱ����
		{
			H = Time2[3] - p->Time[3];
		}
		else if (Time2[3] < p->Time[3])
		{
			D--;
			H = Time2[3] - p->Time[3] + 24;
		}
		else
		{
			printf("�뿪ʱ������");
			return 0;
		}
	}
	else if (Time2[0] = p->Time[0])//������
	{
		if (Time2[1] < p->Time[1])//�·�С��
		{
			printf("�뿪ʱ������");
			return 0;
		}
		else if (Time2[1] >= p->Time[1])
		{
			if (Time2[3] < p->Time[3])//СʱС��
			{
				D = (DL - DC) / 11 - 1;
				H = Time2[3] + 24 - p->Time[3];
				Y = 0;
				M = 0;
				if (D < 0 || H < 0)
				{
					printf("�뿪ʱ������");
					return 0;
				}
			}
			else if (Time2[3] >= p->Time[3])
			{
				D = (DL - DC) / 11;
				H = Time2[3] - p->Time[3];
				Y = 0;
				M = 0;
				if (D < 0 || H < 0)
				{
					printf("�뿪ʱ������");
					return 0;
				}
			}
		}
	}
	if (Loc > S.top - S.base)
	{
		printf("********************************************\n");
		printf("�ô�δͣ�������������3�鿴ͣ�����\n");
		printf("********************************************\n");
		return 0;
	}
	char *E1 = (char*)malloc(5);
	char *E2 = (char*)malloc(5);
	int T1[4], T2[4];
	SqStack S1;
	InitStack(S1);
	while (S.top - S.base - Loc > 0)
	{
		Pop(S, E1, T1);
		Push(S1, E1, T1);
	}
	Pop(S, E1, T1);
	Charge = (Y * 365 * 24 + D * 24 + H) * 20;
	printf("********************************************\n");
	printf("���ƺ�Ϊ%s�ĳ���ͣ����ͣ��%d��%d��%dСʱ,Ӧ����%dԪ\n", E1, Y, D, H, Charge);
	printf("********************************************\n");
	while (S1.top - S1.base > 0)
	{
		Pop(S1, E2, T2);
		Push(S, E2, T2);
	}
	if (DeQueue(Q, E1))//�жϱ�����Ƿ��г�
	{
		Push(S, E1, Time2);//����ϵ�һ��������ͣ����
		printf("���ƺ�Ϊ%s�ĳ�����ͣ������ͣ��%d�ų�λ���볡ʱ��Ϊ%d��%d��%d��%d��\n", E1, S.top - S.base, Time2[0], Time2[1], Time2[2], Time2[3]);
		printf("*******************************************\n");
	}
	return 1;
}

int Checking_Car(SqStack &S, LinkQueue *Q)
{
	if (TravelS(S))
		;
	else
	{
		int i = 1;
		while (i <= N)
		{
			printf("********************************************\n");
			printf("%d��ͣ��λ��δͣ��                          *\n", i);
			i++;
		}
		printf("********************************************\n");
	}
	if (TravelQ(Q))
		;
	else
	{
		printf("���δͣ��                                 *\n");
		printf("********************************************\n");
	}
	return 1;
}

int main()
{
	int Choice;//Choice��ʾѡ��Ĳ�����ţ�i,j���ڱ�ʾ1��2���������պţ�ͣ����λ�ã�������뿪��ʱ��
	char Lic[6];
	int time[4];
	int Loc1;
	int Flag1;
	SqStack S;
	LinkQueue Q;
	InitStack(S);
	InitQueue(&Q);
	printf("****************************\n");
	printf("*��ӭʹ��ͣ��������ϵͳ:   *\n");
	printf("*1:��������                *\n");
	printf("*2:�����뿪                *\n");
	printf("*3:��ʾͣ�����            *\n");
	printf("*4:�˳�ϵͳ                *\n");
	printf("*ͣ������λ����%d           *\n", N);
	printf("****************************\n");
	printf("�����������ţ�");
	scanf("%d", &Choice);
	if (Choice == 1)
	{
		Flag1 = 1;
		printf("****************************\n");
		printf("�����복�ƣ�");
		scanf("%s", Lic);
		printf("****************************\n");
		printf("�����뵽��ʱ�̣�");
		while (Flag1)
		{
			scanf("%d%d%d%d", &time[0], &time[1], &time[2], &time[3]);
			if (time[3] == 24)
			{
				time[3] = 0;
				time[2]++;
			}
			if (time[1] > 12)
			{
				printf("ʱ���������������²���\n");
				printf("�����뵽��ʱ�̣�");
			}
			else if (time[3] > 24)
			{
				printf("ʱ���������������²���\n");
				printf("�����뵽��ʱ�̣�");
			}
			else if (time[2] > 30 && (time[1] == 2 || time[1] == 4 || time[1] == 6 || time[1] == 9 || time[1] == 11))//2��4��6��9��11�·�����Ӧ������30
			{
				printf("ʱ���������������²���\n");
				printf("�����뵽��ʱ�̣�");
			}
			else if (time[2] > 31)
			{
				printf("ʱ���������������²���\n");
				printf("�����뵽��ʱ�̣�");
			}
			else if (time[1] == 2)
			{
				if ((time[0] % 4 == 0) && (time[0] % 100 != 0) || (time[0] % 400 == 0))//Ϊ����
				{
					if (time[2] > 29)
					{
						printf("ʱ���������������²���\n");
						printf("�����뵽��ʱ�̣�");
					}
					else
						Flag1 = 0;
				}
				else
				{
					if (time[2] > 28)
					{
						printf("ʱ���������������²���\n");
						printf("�����뵽��ʱ�̣�");
					}
					else
						Flag1 = 0;
				}
			}
			else
				Flag1 = 0;
		}
	}
	else if (Choice == 2)
	{
		Flag1 = 1;
		printf("****************************\n");
		printf("�����복��λ�ã�");
		scanf("%d", &Loc1);
		printf("****************************\n");
		printf("�������뿪ʱ�̣�");
		while (Flag1)
		{
			scanf("%d%d%d%d", &time[0], &time[1], &time[2], &time[3]);
			if (time[3] == 24)
			{
				time[3] = 0;
				time[2]++;
			}
			if (time[1] > 12)
			{
				printf("ʱ���������������²���\n");
				printf("�������뿪ʱ�̣�");
			}
			else if (time[3] > 24)
			{
				printf("ʱ���������������²���\n");
				printf("�������뿪ʱ�̣�");
			}
			else if (time[2] > 30 && (time[1] == 2 || time[1] == 4 || time[1] == 6 || time[1] == 9 || time[1] == 11))//2��4��6��9��11�·�����Ӧ������30
			{
				printf("ʱ���������������²���\n");
				printf("�������뿪ʱ�̣�");
			}
			else if (time[2] > 31)
			{
				printf("ʱ���������������²���\n");
				printf("�������뿪ʱ�̣�");
			}
			else if (time[1] == 2)
			{
				if ((time[0] % 4 == 0) && (time[0] % 100 != 0) || (time[0] % 400 == 0))//Ϊ����
				{
					if (time[2] > 29)
					{
						printf("ʱ���������������²���\n");
						printf("�������뿪ʱ�̣�");
					}
					else
						Flag1 = 0;
				}
				else
				{
					if (time[2] > 28)
					{
						printf("ʱ���������������²���\n");
						printf("�������뿪ʱ�̣�");
					}
					else
						Flag1 = 0;
				}
			}
			else
				Flag1 = 0;
		}
	}
	while (Choice != 4)
	{
		switch (Choice)
		{
		case 1: {
			Coming_Car(S, &Q, Lic, time);
		}
				break;
		case 2: {
			Leaving_Car(S, &Q, Loc1, time);
		}
				break;
		case 3:Checking_Car(S, &Q);
			break;
		default:printf("��������!\n");
			break;
		}
		printf("�����������ţ�");
		scanf("%d", &Choice);
		if (Choice == 1)
		{
			Flag1 = 1;
			printf("****************************\n");
			printf("�����복�ƣ�");
			scanf("%s", Lic);
			printf("****************************\n");
			printf("�����뵽��ʱ�̣�");
			while (Flag1)
			{
				scanf("%d%d%d%d", &time[0], &time[1], &time[2], &time[3]);
				if (time[3] == 24)
				{
					time[3] = 0;
					time[2]++;
				}
				if (time[1] > 12)
				{
					printf("ʱ���������������²���\n");
					printf("�����뵽��ʱ�̣�");
				}
				else if (time[3] > 24)
				{
					printf("ʱ���������������²���\n");
					printf("�����뵽��ʱ�̣�");
				}
				else if (time[2] > 30 && (time[1] == 2 || time[1] == 4 || time[1] == 6 || time[1] == 9 || time[1] == 11))//2��4��6��9��11�·�����Ӧ������30
				{
					printf("ʱ���������������²���\n");
					printf("�����뵽��ʱ�̣�");
				}
				else if (time[2] > 31)
				{
					printf("ʱ���������������²���\n");
					printf("�����뵽��ʱ�̣�");
				}
				else if (time[1] == 2)
				{
					if ((time[0] % 4 == 0) && (time[0] % 100 != 0) || (time[0] % 400 == 0))//Ϊ����
					{
						if (time[2] > 29)
						{
							printf("ʱ���������������²���\n");
							printf("�����뵽��ʱ�̣�");
						}
						else
							Flag1 = 0;
					}
					else
					{
						if (time[2] > 28)
						{
							printf("ʱ���������������²���\n");
							printf("�����뵽��ʱ�̣�");
						}
						else
							Flag1 = 0;
					}
				}
				else
					Flag1 = 0;
			}
		}
		else if (Choice == 2)
		{
			Flag1 = 1;
			printf("****************************\n");
			printf("�����복��λ�ã�");
			scanf("%d", &Loc1);
			printf("****************************\n");
			printf("�������뿪ʱ�̣�");
			while (Flag1)
			{
				scanf("%d%d%d%d", &time[0], &time[1], &time[2], &time[3]);
				if (time[3] == 24)
				{
					time[3] = 0;
					time[2]++;
				}
				if (time[1] > 12)
				{
					printf("ʱ���������������²���\n");
					printf("�������뿪ʱ�̣�");
				}
				else if (time[3] > 24)
				{
					printf("ʱ���������������²���\n");
					printf("�������뿪ʱ�̣�");
				}
				else if (time[2] > 30 && (time[1] == 2 || time[1] == 4 || time[1] == 6 || time[1] == 9 || time[1] == 11))//2��4��6��9��11�·�����Ӧ������30
				{
					printf("ʱ���������������²���\n");
					printf("�������뿪ʱ�̣�");
				}
				else if (time[2] > 31)
				{
					printf("ʱ���������������²���\n");
					printf("�������뿪ʱ�̣�");
				}
				else if (time[1] == 2)
				{
					if ((time[0] % 4 == 0) && (time[0] % 100 != 0) || (time[0] % 400 == 0))//Ϊ����
					{
						if (time[2] > 29)
						{
							printf("ʱ���������������²���\n");
							printf("�������뿪ʱ�̣�");
						}
						else
							Flag1 = 0;
					}
					else
					{
						if (time[2] > 28)
						{
							printf("ʱ���������������²���\n");
							printf("�������뿪ʱ�̣�");
						}
						else
							Flag1 = 0;
					}
				}
				else
					Flag1 = 0;
			}
		}
	}
	printf("*****************************\n");
	printf("�˳�ϵͳ����ӭ�����´�ʹ�ã�*\n");
	printf("*****************************\n");
	system("pause");
}