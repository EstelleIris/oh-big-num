#include"bigNumQLQ.h"
#include <string>
#include <iostream>
using namespace std;//string ���ͱ�����������ռ�
int main()
{   
	void welcome();//��ӭ����
	int main_operation1();
	int main_operation2();
	int flag=1;	
	char ch;
	system("color F0");//����Ϊ��ɫ,����Ϊ��ɫ
	welcome();
	cout<<"                                     Ŀ¼\n\n";
	cout<<"                           һ.���漰�ļ��Ĵ���������\n\n";
	cout<<"                           ��.�漰�ļ��Ĵ���������"<<endl;
	cout<<"��ѡ��:"<<endl;
	char ah='0';
	ah=getchar();
	getchar();
	fflush(stdin);//�������
	system("cls");
	while(ah>'2'||ah<'1')
	{
		cout<<"����������������������:";
		ah=getchar();
		getchar();
		fflush(stdin);
	}
	switch(ah) 
	{
		case '1': 
			while (flag)
			{
				main_operation1();
				cout<<"\n����?(Y/N)";
				fflush(stdin);//�������
				ch=getchar();
				getchar();   	
				if(ch=='N'||ch=='n')
				flag=0;
				system("cls");
			}
			break;  
			case '2':
			while (flag)
			{
				main_operation2();
				cout<<"\n����?(Y/N)";
				fflush(stdin);//�������
				ch=getchar();
				getchar();   	
				if(ch=='N'||ch=='n')
				flag=0;
				system("cls");
			}
			break;
	}
	return 0;	
}
int main_operation1()//���漰�ļ�����ʱ���ȡ�����
{
	linkedList B1,B2,B3,C;
	bigNum a;
	char ch='0';
	void title();//�������
	title();
	ch=getchar();
	getchar();
	fflush(stdin);
	while(ch>'6'||ch<'1')
	{
		cout<<"����������������������:";
		ch=getchar();
		getchar();
		fflush(stdin);
	}
	switch(ch) 
	{
		case '1':  
			a.input_store(B1,B2,B3);
			cout<<"\n(B1+B2)%B3=";  
			a.add_bigNum(B1,B2,B3); 
			break; 
		case '2':   
			a.input_store(B1,B2,B3);
			cout<<"\n(B1-B2)%B3=";    
			a.sub_bigNum(B1,B2,B3); 
			break; 
		case '3':
			a.input_store(B1,B2,B3);        
			cout<<"\n(B1*B2)%B3=";     
			a.mul_bigNum(B1,B2,B3);  
			break; 
		case '4':   
			a.input_store(B1,B2,B3); 
			cout<<"\n(B1/B2)%B3="; 
			a.div_bigNum(B1,B2,B3);          
			break;
		case '5':
			a.input_store(B1,B2,B3); 
			cout<<"\n(B1^B2)%B3="; 
			a.ind_bigNum(B1,B2,B3);  
			break;
		case '6':   
			exit(0); 
	}
	return 0;
}
int main_operation2()//�漰�ļ�,�������ļ���
{
	linkedList B1,B2,B3,C;
	string m;
	bigNum a;
	char ch='0';
	void ftitle();//�ļ��������
	ftitle();
	ch=getchar();
	getchar();
	fflush(stdin);
	while(ch>'7'||ch<'1')
	{
		cout<<"����������������������:";
		ch=getchar();
		getchar();
		fflush(stdin);
	}
	switch(ch) 
	{
		case '1':  
			a.finput_store(B1,B2);
			cout<<"\n��ӵĺ�Ϊ:"; 
			C=a.add_bigNum(B1,B2); 
			cout<<C;
			m=a.translation(C);
			a.fout_put(m);
			break; 
		case '2':   
			a.finput_store(B1,B2);
			cout<<"\n����Ĳ�Ϊ:"; 
			a.sub_bigNum(B1,B2); 
			break; 
		case '3':   
			a.finput_store(B1,B2);
			cout<<"\n��˵Ļ�Ϊ:";      
			C=a.mul_bigNum(B1,B2); 
			cout<<C;
			m=a.translation(C);
			a.fout_put(m);
			break; 
		case '4':   
			a.finput_store(B1,B2);
			cout<<"\n�������Ϊ:";  
			C=a.div_bigNum(B1,B2);
			//���ڳ���Ϊ0��������صĽ��Ϊ������Ԫ�ڵ����������������ж�
			if(C.size()>0)
			{
				cout<<C;
				m=a.translation(C);
				a.fout_put(m); 
			}
			break;
		case '5':
			a.finput_store(B1,B2);
			cout<<"\n������Ľ��Ϊ:";  
			C=a.ind_bigNum(B1,B2);
			cout<<C;
			m=a.translation(C);
			a.fout_put(m);
			break;
		case '6':
			a.fdisplay();//��Ӳ���������뵽�ڴ棬��ʾ����Ļ
			break;
		case '7':
			exit(0);
	}
	return 0;
}