#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct zhanghu	
{
	char admin[20];
	char password[20];
};
struct shebei
{
	int num;				//���
	char name[200];		//����
	char sys[20];		//����ʵ����
	char date_buy[11];	//��������
	char price[10];		//�۸�
	char kucun[10];		//���
	char date_birth[11];	//��������
	struct shebei *next;
};
int menu_1();					//��¼�˵�
void zhuce();					//�˻�ע��
int denglu();					//�˻���¼
int menu_2();					//���˵�
struct shebei*load();				//�ļ���ȡ������
void save(struct shebei*head);	//����д���ļ�
struct shebei*chuangjian();		//��������������
void show(struct shebei*head);	//�����ӡ
void shebei_add();				//����ĩβ׷��
int shebei_change();				//�豸�޸�
int shebei_del();				//�豸ɾ��
void shebei_find_1();
void shebei_find_1();
void shebei_find_1();
void shebei_find_1();
void shebei_find_1();
int shebei_FIND();				//�豸����
void shebei_tongji();				//��ʵ����ͳ��
void data_exchange(struct shebei*m,struct shebei*n);//�������ڵ�����
void shebei_sort_numup();
void shebei_sort_numdown();
void shebei_sort_nameup();
void shebei_sort_namedown();
void shebei_sort_sysup();
void shebei_sort_sysdown();
int shebei_SORT_MENU();			//����

int main()
{
	int choice_1,choice_2=10;
	printf("\t\t\t\t��ӭʹ��ʵ�����豸����ϵͳ!\n");
	/******************ע���¼****************/
	choice_1=menu_1();
	while(choice_1!=0 && choice_2==10)
	{
		switch(choice_1)
		{
		case 1:choice_2=denglu();break;
		case 2:zhuce();break;
		default:return 0;
		}
		if(choice_2!=11)
		{	
			choice_1=menu_1();}
	}
	/*****************������*******************/
	if(choice_1)
	{
		for(choice_2=menu_2();choice_2!=0;choice_2=menu_2())
			switch(choice_2)
		{
			case 1:system("cls");chuangjian();break;//����
			case 2:system("cls");show(load());break;//��ʾ
			case 3:system("cls");shebei_add();break;//����
			case 4:system("cls");if(shebei_FIND()==1)	
					   printf("���������������������������������������������ɹ�����������������������������������������\n");
				break;//��ѯ
			case 5:system("cls");shebei_tongji();break;//ͳ��
			case 6:if(shebei_change()==1)	
				   {system("cls");
						printf("	�����������������������������������������޸ĳɹ�����������������������������������������\n");}
				   else					
				   {system("cls");
						printf("����-������������������������������δ�ҵ����豸���޸�ʧ�ܡ���-��������������������������\n");}
				   break;//�޸�
			case 7:if(shebei_del()==1)	
				   {system("cls");
						printf("����������������������������������������ɾ���ɹ�����������������������������������������\n");}
				   else					
				   {system("cls");
						printf("����������������������������������-δ�ҵ����豸���޸�ʧ�ܡ�����������������������������-\n");}
				   break;//ɾ��
			case 8:system("cls");if(shebei_SORT_MENU()==1);
						printf("���������������������������������������������ɹ�����������������������������������������\n");
					break;//����
			default:;
		}
	}
}

/*
***************��ʼ����*******************************************
*/
int menu_1()
{
	int n;
	printf("\t\t\t\t********************************\n");
	printf("\t\t\t\t*           1.��¼             *\n");
	printf("\t\t\t\t*           2.ע��             *\n");
	printf("\t\t\t\t*           0.�˳�             *\n");
	printf("\t\t\t\t********************************\n");
	printf("����������ѡ��");
	scanf("%d",&n);
	return n;
}

void zhuce()
{
	FILE*fp;
	char yhm[20],mima_0[20],mima_1[20];
	struct zhanghu s;
	struct zhanghu*p=&s;
	int t=0,i,m=0;
	do{
		printf("�������û�����\n");
		scanf("%s",yhm);
		printf("���������룺\n");
		scanf("%s",mima_0);
		printf("����һ���������룺\n");
		scanf("%s",mima_1);
		if(strcmp(mima_0,mima_1)==0)
			{system("cls");
			 printf("ע��ɹ���\n");
			 t=1;
			break;}
		else
		{
			m++;
			if(m>2)	{system("cls");printf("����3�����벻һ�£����˳��˲�����\n");}
			else printf("���벻һ�£����������룺\n");}
	}while(t==0 && m<3);
/***********���浽�˻��ļ�**************************************/
	if(m<3)
	{
	for(i=0;mima_0[i]!='\0';i++)
		mima_0[i]+=10;                                     //�������
	strcpy(p->admin,yhm);		strcpy(p->password,mima_0);
	if((fp=fopen("zhanghu.txt","ab"))==NULL)
		{printf("cuowu0");exit(0);}
	if((fwrite(&s,sizeof(struct zhanghu),1,fp))!=1)
		{printf("д�����ݴ���");exit(0);}
	fclose(fp);
	}
}

int denglu()
{
	struct zhanghu read;
	struct zhanghu*p=&read;
	char yhm[20],mima[20];
	FILE*fp;
	int n=0,i,j,t=0;
	if((fp=fopen("zhanghu.txt","rb"))==NULL)
	{	system("cls");
		printf("�������˻��ļ�����ע��\n");return 10;}
	for(i=4;i>=0;i--)
	{
		printf("�������û�����\n");
		scanf("%s",yhm);
		printf("���������룺\n");
		scanf("%s",mima);
		rewind(fp);
		while(t==0 && fp!=NULL && n==0)
		{
		if((fread(&read,sizeof(struct zhanghu),1,fp))!=NULL)
		{if(strcmp(p->admin,yhm)==0)	
			{
				t=1;n=1;
				for(j=0;p->password[j]!='\0';j++)
					p->password[j]-=10;					//�������
				if(strcmp(p->password,mima)==0)
					{system("cls");
					printf("��¼�ɹ���\n");
					return 11;}
				else		
				{
					n=0;t=0;					
					if(i==4)
					{	system("cls");
						printf("�û�������������������������룡\n");}
					else
					{	system("cls");
						printf("��¼ʧ�ܣ�������%d�λ��ᣡ\n",i);
						if(i==0) return 10;
					}
					break;
				}
			}
		}
		else 
			{system("cls");
			printf("���˻������ڣ�\n");
			return 10;}
		}
	}
	fclose(fp);
}

/*
***************���˵�*********************************************
*/
int menu_2()
{
	int n;
	printf("\t\t\t\t********************************\n");
	printf("\t\t\t\t*         1.���������ݱ�       *\n");
	printf("\t\t\t\t*         2.��ʾ�豸��Ϣ       *\n");
	printf("\t\t\t\t*         3.�����豸           *\n");
	printf("\t\t\t\t*         4.��ѯ�豸           *\n");
	printf("\t\t\t\t*         5.ͳ���豸           *\n");
	printf("\t\t\t\t*         6.�޸��豸           *\n");
	printf("\t\t\t\t*         7.ɾ���豸           *\n");
	printf("\t\t\t\t*         8.���豸����         *\n");
	printf("\t\t\t\t*         0.�˳�               *\n");
	printf("\t\t\t\t********************************\n");
	printf("����������ѡ��");
	scanf("%d",&n);
	return n;
}

struct shebei*load()
{
    struct shebei*head,*p,*q,*tail;FILE*fp;char ch;
	head=NULL,p=NULL;
	if((fp=fopen("shebei.txt","rb"))==NULL)
	{printf("���豸�ļ�ʧ�ܣ�");return;}
	if(ch=getc(fp)==EOF)	{head==NULL;return head;}
	else fseek(fp,-1L,1);
	while(ch=getc(fp)!=EOF)
	{
		fseek(fp,-1L,1);
		q=(struct shebei*)malloc(sizeof(struct shebei));
		fscanf(fp,"%d%s%s%s%s%s%s\n",&q->num,q->name,q->sys,q->date_buy,q->price,q->kucun,q->date_birth);
		if(head==NULL)
	{head=q;head->next=NULL;p=head;}
	else{
	p->next=q;
	p=q;}
	}
	p->next=NULL;
	fclose(fp);
	return head;
}

void save(struct shebei*head)
{	
	struct shebei*q;FILE*fp;
	q=head;
	
	if((fp=fopen("shebei.txt","wb"))==NULL)
	{printf("���豸�ļ�ʧ�ܣ�");return;}
	while(q)
	{
		fprintf(fp,"%d %s %s %s %s %s %s\n",q->num,q->name,q->sys,q->date_buy,q->price,q->kucun,q->date_birth);
		q=q->next;
	}
	fclose(fp);
}

struct shebei*chuangjian()
{
	
	struct shebei*head,*p,*tail;
	int number,r;
	head=NULL;
	tail=NULL;
	printf("\t\t����\n�˲�����ɾ��֮ǰ���������ݣ��Ƿ������\n\t1.����\n\t2.�˳�\n����������ѡ��");
	scanf("%d",&r);
	if(r==2)	return NULL;
	system("cls");
	printf("�������豸���(����0����)��");
	scanf("%d",&number);
	while(number!=0)
	{
		
		p=(struct shebei*)malloc(sizeof(struct shebei));
		p->num=number;
		/********************��������**********************/
		printf("�������豸���ƣ�");	scanf("%s",p->name);
		printf("����������ʵ���ң�");	scanf("%s",p->sys);
		printf("�����빺�����ڣ��á�-����������");scanf("%s",p->date_buy);
		printf("������۸�");		scanf("%s",p->price);
		printf("�������棺");		scanf("%s",p->kucun);
		printf("�������������ڣ��á�-����������");	scanf("%s",p->date_birth);
		/********************��������*********************/
		p->next=NULL;
		if(head==NULL)	head=p;
		else		tail->next=p;
		tail=p;
		system("cls");
		printf("�������¸��豸�ı��(����0����)��");
		scanf("%d",&number);
	}
	save(head);
	return head;
}

void show(struct shebei*head)
{
	struct shebei*p;
	p=head;
	if(head==NULL)	{printf("�����ݣ�\n");return;}
	printf("���   �豸����            ����ʵ����   ��������      �۸�     ���       ��������\n");
	while(p)
	{
		printf("%5d %-20s %-10s   %-10s  %-10s %-10s %-10s\n",p->num,p->name,p->sys,p->date_buy,p->price,p->kucun,p->date_birth);
		p=p->next;
	}
}

void shebei_add()
{
	struct shebei*head,*p,*tail,*q;
	int number;
	head=load();p=head;
	if(head==NULL)	{printf("���κ����ݣ��봴����\n");return;}
	while(p->next!=NULL)	p=p->next;
	tail=p;
	printf("�������豸��ţ�����0��������");
	scanf("%d",&number);
	while(number!=0)
	{
		
		q=(struct shebei*)malloc(sizeof(struct shebei));
		q->num=number;
		/********************��������**********************/
		printf("�������豸���ƣ�");	scanf("%s",q->name);
		printf("����������ʵ���ң�");	scanf("%s",q->sys);
		printf("�����빺�����ڣ��á�-����������");scanf("%s",q->date_buy);
		printf("������۸�");		scanf("%s",q->price);
		printf("�������棺");		scanf("%s",q->kucun);
		printf("�������������ڣ��á�-����������");	scanf("%s",q->date_birth);
		/********************��������*********************/
		q->next=NULL;
		if(tail==NULL)	tail=q;
		else		tail->next=q;
		tail=q;
		system("cls");
		printf("�������¸��豸�ı��(����0����)��");
		scanf("%d",&number);
	}
	save(head);

}

void shebei_find_1()
{
	struct shebei*head,*p;int n=0,sum=0,temp;
	head=load();p=head;
	printf("�������豸��ţ�");	scanf("%d",&temp);
	do
	{
		if(head==NULL)	{printf("�����ݣ�\n");return;}
		else
		{
			if(p->num==temp)
			{
				if(sum==0)	printf("���   �豸����            ����ʵ����   ��������      �۸�     ���       ��������\n");				
				printf("%5d %-20s %-10s   %-10s  %-10s %-10s %-10s\n",p->num,p->name,p->sys,p->date_buy,p->price,p->kucun,p->date_birth);
				sum++;
			}
			n++;
			p=p->next;
		}
	}while(p!=NULL);
	if(sum==0)	printf("δ�ҵ��豸���Ϊ%d������!\n",temp);
}
void shebei_find_2()
{
	struct shebei*head,*p;int n=0,sum=0;char str[20];
	head=load();p=head;
	printf("�������豸���ƣ�");	scanf("%s",str);
	do
	{
		if(p==NULL)	{printf("�����ݣ�\n");return;}
		else
		{
			if(strcmp(p->name,str)==0)
			{
				if(sum==0)	printf("���   �豸����            ����ʵ����   ��������      �۸�     ���       ��������\n");				
				printf("%5d %-20s %-10s   %-10s  %-10s %-10s %-10s\n",p->num,p->name,p->sys,p->date_buy,p->price,p->kucun,p->date_birth);
				sum++;
			}
			n++;
			p=p->next;
		}
	}while(p!=NULL);
	if(sum==0)	printf("δ�ҵ��豸����Ϊ%s������!\n",str);
}
void shebei_find_3()
{
	struct shebei*head,*p;int n=0,sum=0;char str[20];
	head=load();p=head;
	printf("�������豸����ʵ���ң�");	scanf("%s",str);
	do
	{
		if(p==NULL)	{printf("�����ݣ�\n");return;}
		else
		{
			if(strcmp(p->sys,str)==0)
			{
				if(sum==0)	printf("���   �豸����            ����ʵ����   ��������      �۸�     ���       ��������\n");				
				printf("%5d %-20s %-10s   %-10s  %-10s %-10s %-10s\n",p->num,p->name,p->sys,p->date_buy,p->price,p->kucun,p->date_birth);
				sum++;
			}
			n++;
			p=p->next;
		}
	}while(p!=NULL);
	if(sum==0)	printf("δ�ҵ�����ʵ����Ϊ%s������!\n",str);
}
void shebei_find_4()
{
	struct shebei*head,*p;int n=0,sum=0;char str1[20],str2[20];
	head=load();p=head;
	printf("�������豸���Ƽ�����ʵ���ң�");	scanf("%s%s",str1,str2);
	do
	{
		if(p==NULL)	{printf("�����ݣ�\n");return;}
		else
		{
			if(strcmp(p->name,str1)==0 && strcmp(p->sys,str2)==0)
			{
				if(sum==0)	printf("���   �豸����            ����ʵ����   ��������      �۸�     ���       ��������\n");				
				printf("%5d %-20s %-10s   %-10s  %-10s %-10s %-10s\n",p->num,p->name,p->sys,p->date_buy,p->price,p->kucun,p->date_birth);
				sum++;
			}
			n++;
			p=p->next;
		}
	}while(p!=NULL);
	if(sum==0)	printf("δ�ҵ��豸����Ϊ%s������ʵ����Ϊ%s������!\n",str1,str2);
}
int shebei_FIND()
{
	int n;
	printf("��ѡ����ҷ�ʽ\n\t1.���\n\t2.�豸����\n\t3.����ʵ����\n\t4.�豸����&����ʵ����\n\t0.�˳��˲���\n����������ѡ��");
	scanf("%d",&n);
	if(n==0)		return 0;
	switch(n)
	{
	case 1:shebei_find_1();break;
	case 2:shebei_find_2();break;
	case 3:shebei_find_3();break;
	case 4:shebei_find_4();break;
	default:;
	}
	return 1;
}

int shebei_change()
{
	struct shebei*head,*p,*q;int Num,r=0,num_0;
	head=load();p=head;
	printf("������Ҫ�޸ĵ��豸��ţ�");
	scanf("%d",&Num);
	do
	{
		if(p->num==Num)	{r=1;break;}
		else {q=p;p=p->next;}
	}while(q->next!=NULL);
	if(r==0)		{printf("δ�ҵ����豸��\n");return 0;}
	else
	{
		printf("�������豸���(����0���˳��˲����Ҳ�����)��");	
		scanf("%d",&num_0);
		if(num_0==0)	return 0;else p->num=num_0;
		printf("�������豸���ƣ�");	scanf("%s",p->name);
		printf("����������ʵ���ң�");	scanf("%s",p->sys);
		printf("�����빺�����ڣ��á�-����������");scanf("%s",p->date_buy);
		printf("������۸�");		scanf("%s",p->price);
		printf("�������棺");		scanf("%s",p->kucun);
		printf("�������������ڣ��á�-����������");	scanf("%s",p->date_birth);
	}
	save(head);
	return 1;
}

int shebei_del()
{
	struct shebei*head,*p,*q;int Num,r=0;
	head=load();p=head;
	printf("������Ҫɾ�����豸��ţ�");
	scanf("%d",&Num);
	do
	{
		if(p->num==Num)	{r=1;break;}
		else {q=p;p=p->next;}
	}while(q->next!=NULL);
	if(r==0)		{printf("δ�ҵ����豸��\n");return 0;}
	else
	{
		if(p==head)	head=p->next;
		else		q->next=p->next;
		free(p);
	}
	save(head);
	return 1;
}

void shebei_tongji()
{
	struct shebei*head,*p;int num=0,n[5]={0};
	head=load();p=head;
	do
	{
		if(head==NULL)	{printf("����Ϊ0\n");return;}
		if(strcmp(p->sys,"wuli")==0)	n[0]++;
		else
			if(strcmp(p->sys,"huaxue")==0)	n[1]++;
			else
				if(strcmp(p->sys,"shengwu")==0)		n[2]++;
				else
					if(strcmp(p->sys,"jisuanji")==0)	n[3]++;
					else		n[4]++;
		num++;
		p=p->next;
	}while(p!=NULL);
	printf("����%d�����ݣ����У�\n",num);
	if(n[0]!=0)	printf("��������ʵ���ҵ���%d��\n",n[0]);
	if(n[1]!=0)	printf("���ڻ�ѧʵ���ҵ���%d��\n",n[1]);
	if(n[2]!=0)	printf("��������ʵ���ҵ���%d��\n",n[2]);
	if(n[3]!=0)	printf("���ڼ����ʵ���ҵ���%d��\n",n[3]);
	if(n[4]!=0)	printf("��������ʵ���ҵ���%d��\n",n[4]);
}

void data_exchange(struct shebei*m,struct shebei*n)
{	
	int numt;char namet[20],syst[10],datebuyt[11],pricet[10],kucunt[10],datebirtht[11];
	struct shebei*q,*p;
	p=m,q=n;
	numt=p->num;
	strcpy(namet,p->name);
	strcpy(syst,p->sys);
	strcpy(datebuyt,p->date_buy);
	strcpy(pricet,p->price);
	strcpy(kucunt,p->kucun);
	strcpy(datebirtht,p->date_birth);//�����м����
	p->num=q->num;
	strcpy(p->name,q->name);
	strcpy(p->sys,q->sys);
	strcpy(p->date_buy,q->date_buy);
	strcpy(p->price,q->price);
	strcpy(p->kucun,q->kucun);
	strcpy(p->date_birth,q->date_birth);//q��ָ���ݸ���p
	q->num=numt;
	strcpy(q->name,namet);
	strcpy(q->sys,syst);
	strcpy(q->date_buy,datebuyt);
	strcpy(q->price,pricet);
	strcpy(q->kucun,kucunt);
	strcpy(q->date_birth,datebirtht);//�м��������q
}
void shebei_sort_numup()
{
	struct shebei*head,*p,*q;
	head=load();p=head;q=p->next;
	while(p!=NULL)
	{
		q=p->next;
		while(q!=NULL)
		{
			if(q->num<p->num)
			{
				data_exchange(p,q);
			}
			q=q->next;
		}
		p=p->next;
	}
	show(head);
}
void shebei_sort_numdown()
{
	struct shebei*head,*p,*q;
	head=load();p=head;q=p->next;
	while(p!=NULL)
	{
		q=p->next;
		while(q!=NULL)
		{
			if(q->num>p->num)
			{
				data_exchange(p,q);
			}
			q=q->next;
		}
		p=p->next;
	}
	show(head);
}
void shebei_sort_nameup()
{
	struct shebei*head,*p,*q;
	head=load();p=head;q=p->next;
	while(p!=NULL)
	{
		q=p->next;
		while(q!=NULL)
		{
			if(strcmp(q->name,p->name)<0)
			{
				data_exchange(p,q);
			}
			q=q->next;
		}
		p=p->next;
	}
	show(head);
}
void shebei_sort_namedown()
{
	struct shebei*head,*p,*q;
	head=load();p=head;q=p->next;
	while(p!=NULL)
	{
		q=p->next;
		while(q!=NULL)
		{
			if(strcmp(q->name,p->name)>0)
			{
				data_exchange(p,q);
			}
			q=q->next;
		}
		p=p->next;
	}
	show(head);
}
void shebei_sort_sysup()
{
	struct shebei*head,*p,*q;
	head=load();p=head;q=p->next;
	while(p!=NULL)
	{
		q=p->next;
		while(q!=NULL)
		{
			if(strcmp(q->sys,p->sys)<0)
			{
				data_exchange(p,q);
			}
			q=q->next;
		}
		p=p->next;
	}
	show(head);
}
void shebei_sort_sysdown()
{
	struct shebei*head,*p,*q;
	head=load();p=head;q=p->next;
	while(p!=NULL)
	{
		q=p->next;
		while(q!=NULL)
		{
			if(strcmp(q->sys,p->sys)>0)
			{
				data_exchange(p,q);
			}
			q=q->next;
		}
		p=p->next;
	}
	show(head);
}
int shebei_SORT_MENU()
{
	int a,b;
	printf("���밴���ַ�ʽ����\n\t1.�����\n\t2.������\n\t3.������ʵ����\n\t0.�˳��˲���\n�����룺");
	scanf("%d",&a);
	if(a==0)	return 0;
	printf("��ѡ���������\n\t1.����\n\t2.����\n�����룺");
	scanf("%d",&b);
	switch(a)
	{
	case 1:
			if(b==1)	shebei_sort_numup();
		    else		shebei_sort_numdown();break;
	case 2:
			if(b==1)	shebei_sort_nameup();
		    else		shebei_sort_namedown();break;
	case 3:
			if(b==1)	shebei_sort_sysup();
		    else		shebei_sort_sysdown();break;
	}
	return 1;
}