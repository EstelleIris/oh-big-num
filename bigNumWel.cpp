#include"bigNumQLQ.h"
#include<string>//�ַ���ͷ�ļ�
#include <iostream>//�������������
#include<fstream>//�ļ����������������iostream
#include<sstream>//�����ṩ�����string����֮���I/O
#include <ctime>//��¼��������ʱ��
using namespace std;//�����ռ� std::cout c++�������еı�ʶ��������һ����Ϊstd�������ռ��ж����

//********************************************************����********************************************************
//��ӡ��ӭ���� 
void welcome()
 {
	cout<<"================================================================================\n\n";     
	cout<<"                           ��ӭʹ�ó������������\n\n";     
	cout<<"*�밴������ʾ���в���:\n\n";  
	cout<<"*���ȣ�������Ļ����ʾѡ��������еĲ�����\n\n";  
	cout<<"*��Σ�������ʾ����������������������\n\n";  
	cout<<"\n\n";  
	cout<<"              ����:Ǯ����  �༶:�������1405��  ѧ��:201427920214\n";     
	cout<<"================================================================================";
	cout<<"                               \n\n"; 
}
//��ӡ���ⴰ��
void title()
{  
	int i; 
	cout<<endl;
	for(i=0;i<35;i++)   
	    cout<<"*";  
	cout<<"����������";  
	for(i=0;i<35;i++)   
		cout<<"*";  
	cout<<"\n";
	cout<<"                          ����1��2��3��4��5��6ѡ�����:              \n";  
	cout<<"                                    1���ӷ�                              \n";  
	cout<<"                                    2������                              \n";  
	cout<<"                                    3���˷�                              \n"; 
	cout<<"                                    4������                              \n"; 
	cout<<"                                    5��ָ��                              \n"; 
	cout<<"                                    6���˳�                              \n";    
	cout<<"========================================= ======================================\n";
	cout<<"��ѡ��:";		 
}  
//��ӡ�ļ����뷽ʽ�ı��ⴰ��
void ftitle()
{  
	int i; 
	cout<<endl;
	for(i=0;i<35;i++)   
		cout<<"*";  
	cout<<"����������";  
	for(i=0;i<35;i++)   
		cout<<"*";  
	cout<<"\n";
	cout<<"                         ����1��2��3��4��5��6ѡ�����:              \n";  
	cout<<"                                    1���ӷ�                              \n";  
	cout<<"                                    2������                              \n";  
	cout<<"                                    3���˷�                              \n"; 
	cout<<"                                    4������                              \n"; 
	cout<<"                                    5��ָ��                              \n"; 
	cout<<"                                    6���ļ�                              \n";
    cout<<"                                    7���˳�                              \n";
	cout<<"========================================= ======================================\n";
	cout<<"��ѡ��:";		 
}
  
//********************************************************˫��ѭ��������********************************************************
//���캯��
linkedList::linkedList()
{
    node* dummynode=new node();//�ڹ��캯���н�����Ԫ�ڵ�,dummynode��Ϊ��Ԫ�ڵ�
	dummynode->prev=dummynode;
	dummynode->next=dummynode;
	head=dummynode;
	lsize=0;//����Ԫ�ڵ��������Ϊ0
}



//�������캯��
linkedList::linkedList(const linkedList & obj)
{
//�Զ����˿������캯���������ÿ������캯��ʱ�������Ĭ�Ϲ��캯��
	if(obj.size()==0)//��Խ�������Ԫ�ڵ�Ŀ�����Ŀ���
	{
	      node* dummynode=new node();
	      dummynode->prev=dummynode;
	      dummynode->next=dummynode;
	      head=dummynode;
	      lsize=0;
	}
	else
	{
		node* dummynode=new node();//��Ԫ�ڵ�Ĺ���
	    dummynode->prev=dummynode;
     	dummynode->next=dummynode;
	    head=dummynode;
     	lsize=0;
	    node*front=NULL,*newNode,*back;//��Ԫ�ڵ���󲿷������ܵĹ���
	    node*ptr=obj.head->next;
	    int n=obj.size();
        int i=0;
        while(i<n)//��ǰ����ʵ������Ĵ���
		{	
		    if(i==0)//������һ���ڵ�
			{
		       front=new node();
		       back=front;
		       front->data=ptr->data;
		       ptr=ptr->next;
			}
	        else//����֮��ڵ�
			{
		       newNode=new node();
		       back->next=newNode;
		       newNode->prev=back;
		       back=back->next;
		       back->data=ptr->data;
		       ptr=ptr->next;
			}
	     i++;
		}
        head->next=front;//����Ԫ�ڵ�ָ���½��õ������ͷ�ڵ�
	    front->prev=head;
	    back->next=head;
     	head->prev=back;
	    lsize=n;//��ʱ������Ϊn
	}
}



//��ֵ����
linkedList & linkedList ::operator=(const linkedList& rhs)
{
//�Զ����˿������캯���������ÿ������캯��ʱ�������Ĭ�Ϲ��캯��
	if(rhs.size()==0)//��Խ�������Ԫ�ڵ�Ŀ�����ִ�и�ֵ����
	{
		node* dummynode=new node();
	    dummynode->prev=dummynode;
     	dummynode->next=dummynode;
	    head=dummynode;
     	lsize=0;
	}
	else
	{
		node*front=NULL,*newNode,*back;
	    node*ptr=rhs.head->next;
	    int n=rhs.size();
        int i=0;
        while(i<n)//��ǰ����ʵ������Ĵ���
		{	
		    if(i==0)//������һ���ڵ�
			{
		        front=new node();
		        back=front;
		        front->data=ptr->data;
		        ptr=ptr->next;
			}
	        else//����֮��ڵ�
			{
				newNode=new node();
		        back->next=newNode;
		        newNode->prev=back;
		        back=back->next;
		        back->data=ptr->data;
		        ptr=ptr->next;
			}
	        i++;
		}
        head->next=front;//����Ԫ�ڵ�ָ���½��õ������ͷ�ڵ�
	    front->prev=head;
	    back->next=head;
	    head->prev=back;
	    lsize=n;//��ʱ������Ϊn
	}
    return *this;
}


//˫��ѭ������Ĵ�������ֵ
void linkedList::create_linkedList1(int n)
{
    node*front=NULL,*newNode,*back;
    int i=0;
    while(i<n)//��ǰ����ʵ������Ĵ���
	{	
		if(i==0)//������һ���ڵ㲢�����ݲ��ֳ�ʼ��
		{
		front=new node(0,NULL,NULL);
		back=front;
		}
	    else//����֮��ڵ�
		{
		newNode=new node(0,NULL,NULL);//�����ݲ��ֳ�ʼ��
		back->next=newNode;
		newNode->prev=back;
		back=back->next;
		}
	i++;
	}
    head->next=front;
	front->prev=head;
	back->next=head;
	head->prev=back;
	lsize=n;//��ʱ������Ϊn
}



//˫��ѭ������Ĵ�����������ֵ
void linkedList::create_linkedList2(int n)
{
    node*front=NULL,*newNode,*back;
    int i=0;
    while(i<n)//��ǰ����ʵ������Ĵ���
	{	
		if(i==0)//������һ���ڵ�
		{
		front=new node();
		back=front;
		}
	    else//����֮��ڵ�
		{
		newNode=new node();
		back->next=newNode;
		newNode->prev=back;
		back=back->next;
		}
	i++;
	}
    head->next=front;//����Ԫ�ڵ�ָ���½��õ������ͷ�ڵ�
	front->prev=head;
	back->next=head;
	head->prev=back;
	lsize=n;//��ʱ������Ϊn
}



//������,����Ա�������޷��޸ı����е����ݳ�Ա
int linkedList::size()const
{
	return lsize;
	//lsize=lsize+1;//�޸ģ����Ա���
}



//���뺯��
void linkedList::insert(int item, int pos)//��������item��pos��
{
	int i;
	node*newptr,*preptr,*ptr;
	newptr=new node(item,NULL);//�½��ڵ㣬���ݲ���Ϊitem
	preptr=head;
	ptr=preptr->next;
	for(i=0;i<pos;i++)//ѭ���ҵ���Ҫ����ڵ��λ��
	{
		preptr=preptr->next;//�ڵ�ǰ
		ptr=ptr->next;//�ڵ��
	}
    newptr->next=preptr->next;
	preptr->next=newptr;
	ptr->prev=newptr;
	newptr->prev=preptr;
	lsize=lsize+1;//��������1
}



//ɾ������
void linkedList::erase(int pos)//ɾ��pos���Ľڵ�
{
	int i;
	node*preptr,*ptr,*beptr;
	preptr=head;
	ptr=preptr->next;
	beptr=ptr->next;
	for(i=1;i<pos;i++)//ѭ���ҵ�ɾ���ڵ��λ��
	{
		preptr=preptr->next;//λ��ǰ
		ptr=ptr->next;//ɾ���ڵ��λ��
		beptr=beptr->next;//λ�ú�
	}
	preptr->next=beptr;
	beptr->prev=preptr;
	delete ptr;//�ͷŽڵ�ռ䣬ɾ��
	lsize=lsize-1;//�����Լ�1
}



//�������
void linkedList::display(ostream & out)
{
	int i; 
	node*temp;
	temp=head->next;
	for(i=0;i<lsize;i++)//ѭ��������������һ���
	{
		out<<temp->data;
		temp=temp->next;
	}
}



//����λ�����������
ostream & operator<<(ostream & out,  linkedList & aList )
{
	aList.display(out);
	return out;
}



//********************************************************��������********************************************************
//�����ȱȽ�
int bigNum::cmplinklen(linkedList& opr1,linkedList& opr2)
{
	int m=opr1.size();//opr1�ĳ���
	int n=opr2.size();//opr2�ĳ���
    if(m>=n) return 1;
	else return -1;
}



//�Ƚ������������Ĵ�С,�Ƚ���Ϻ�1����opr1>opr2,-1����opr1<opr2,0����opr1=opr2
int bigNum::compare(linkedList& opr1,linkedList &opr2)
{   int m=0; 
	int l1=opr1.size();
	int l2=opr2.size();
    if(l1>l2)//opr1���ȴ���opr2���� 
		m=1;
	else if(l1==l2)//�������
	{
		node*optr1=opr1.head->next;
		node*optr2=opr2.head->next;
		for(int i=0;i<l1;i++)//�������ʱ�ַ��������
		{
			if(optr1->data>optr2->data)
			{
				m=1;break;//�����������ѭ��
			}
			else if(optr1->data<optr2->data)
			{
				m=-1;break;//�����������ѭ��
			}
			optr1=optr1->next;
			optr2=optr2->next;

		}
	}
	else  m=-1;//opr1����С��opr2
    return m;
}



//����������ת�����ַ���
string bigNum::translation(linkedList &opr)//�����ý��������ļ���
{   
    node*back;
	int l=opr.size();
	string s(l,0);//��������Ϊl����ʼ��Ϊ0���ַ���
	back=opr.head->prev;
	for(int i=l-1;i>=0;i--)//ѭ���������������뵽�ַ�����
	{
		s[i]=back->data+'0';
		back=back->prev;
	}
	return s;
}



//���������ַ������͵Ĳ�����,������洢��������
void bigNum::input_store(linkedList& opr1,linkedList &opr2)//�����β�
{
	int length;
	node*back;
	int i;
	cout<<"�������һ��������:";
	string s1;
	cin>>s1;
	length=s1.length();
    opr1.create_linkedList2(length);//��opr1�����ɳ���Ϊlength������
	back=opr1.head->prev;
	for(i=length-1;i>=0;i--)//ѭ������洢��������
	{
		back->data=s1[i]-'0';
		back=back->prev;
	}
	cout<<"������ڶ���������:";
    string s2;
	cin>>s2;
	length=s2.length();
	opr2.create_linkedList2(length);//��opr1�����ɳ���Ϊlength������
	back=opr2.head->prev;
	for( i=length-1;i>=0;i--)//ѭ������洢��������
	{
		back->data=s2[i]-'0';
		back=back->prev;
	}
}



//���������ַ������͵Ĳ�����,������洢��������
void bigNum::input_store(linkedList& opr1,linkedList &opr2,linkedList &opr3)//�����β�
{
	int length;
	node*back;
	int i;
	cout<<"�������һ��������B1:";
	string s1;
	cin>>s1;
	length=s1.length();
    opr1.create_linkedList2(length);//��opr1�����ɳ���Ϊlength������
	back=opr1.head->prev;
	for(i=length-1;i>=0;i--)//ѭ������洢��������
	{
		back->data=s1[i]-'0';
		back=back->prev;
	}
	cout<<"������ڶ���������B2:";
    string s2;
	cin>>s2;
	length=s2.length();
	opr2.create_linkedList2(length);//��opr1�����ɳ���Ϊlength������
	back=opr2.head->prev;
	for( i=length-1;i>=0;i--)//ѭ������洢��������
	{
		back->data=s2[i]-'0';
		back=back->prev;
	}
	cout<<"�������������ģ��B3:";
    string s3;
	cin>>s3;
	length=s3.length();
	opr3.create_linkedList2(length);//��opr1�����ɳ���Ϊlength������
	back=opr3.head->prev;
	for( i=length-1;i>=0;i--)//ѭ������洢��������
	{
		back->data=s3[i]-'0';
		back=back->prev;
	}
}



//���ļ�f1�ĵ�n�����ݴ洢��������
void bigNum::finput_store(linkedList& opr1,linkedList &opr2)//�����β�
{  
	//ֱ�ӽ��ļ��е�n�е����ݶ��뵽�ڴ���   
	int n1;
	cout<<"�������һ��������Ҫ��ȡ������"<<endl;
    cin>>n1;
	//��һ����������ȡ�ļ��еĵ�n1���ַ���
    ifstream in1("f:\\f1.txt");//�������ʽ���ļ�   
    string line1;  
    if(in1) // �и��ļ�  
    {  
		for(int i=0;i<n1;i++)//�ҵ��ļ��еĵ�n��
             getline (in1, line1);
        cout<<line1<<endl;   
    }  
    else // û�и��ļ�  
    {  
        cout <<"no such file" << endl;  
    }
	in1.close();
    //�ڶ�����������ȡ�ļ��еĵ�n2���ַ���
    ifstream in2("f:\\f1.txt");//�������ʽ���ļ� 
	int n2;
	cout<<"������ڶ���������Ҫ��ȡ������"<<endl;
    cin>>n2; 
    string line2;  
    if(in2) // �и��ļ�  
    {  
		for(int i=0;i<n2;i++)//�ҵ��ļ��еĵ�n2��
             getline (in2, line2);
        cout<<line2<<endl;  
   
    }  
    else // û�и��ļ�  
    {  
        cout <<"no such file" << endl;  
    }
	in2.close();
    //��line1��line2�ֱ𸳸�����B1,B2
	//��һ��
	node*back;
	int i;
	int length=line1.length();
    opr1.create_linkedList2(length);
	back=opr1.head->prev;
	for(i=length-1;i>=0;i--)
	{
		back->data=line1[i]-'0';
		back=back->prev;
	}
    //�ڶ���
	length=line2.length();
	opr2.create_linkedList2(length);
	back=opr2.head->prev;
	for( i=length-1;i>=0;i--)
	{
		back->data=line2[i]-'0';
		back=back->prev;
	}
}



//���ļ��еĵ�n�����ݴ洢��������
void bigNum::finput_store(linkedList& opr1,linkedList &opr2,linkedList &opr3)//�����β�
{  
	//ֱ�ӽ��ļ��е�n�е����ݶ��뵽�ڴ���   
	int n1;
	cout<<"�������һ��������Ҫ��ȡ������"<<endl;
    cin>>n1;
	//��һ����������ȡ�ļ��еĵ�n1���ַ���
    ifstream in1("f:\\f1.txt");   
    string line1;  
    if(in1) // �и��ļ�  
    {  
		for(int i=0;i<n1;i++)//�ҵ��ļ��еĵ�n��
             getline (in1, line1);//��ȡ����
        cout<<line1<<endl;   
    }  
    else // û�и��ļ�  
    {  
        cout <<"no such file" << endl;  
    }
	in1.close();
    //�ڶ�����������ȡ�ļ��еĵ�n2���ַ���
    ifstream in2("f:\\f1.txt");
	int n2;
	cout<<"������ڶ���������Ҫ��ȡ������"<<endl;
    cin>>n2; 
    string line2;  
    if(in2) // �и��ļ�  
    {  
		for(int i=0;i<n2;i++)//�ҵ��ļ��еĵ�n2��
             getline (in2, line2);//��ȡ����
        cout<<line2<<endl;  
   
    }  
    else // û�и��ļ�  
    {  
        cout <<"no such file" << endl;  
    }
	in2.close();
    //��һ����������ȡ�ļ��еĵ�n1���ַ���
	ifstream in3("f:\\f1.txt");
	int n3;
	cout<<"������ڶ���������Ҫ��ȡ������"<<endl;
    cin>>n3; 
    string line3;  
    if(in3) // �и��ļ�  
    {  
		for(int i=0;i<n3;i++)//�ҵ��ļ��еĵ�n3��
             getline (in3, line3);//��ȡ����
        cout<<line3<<endl;  
   
    }  
    else // û�и��ļ�  
    {  
        cout <<"no such file" << endl;  
    }
	in3.close();
    //��line1��line2��line3�ֱ𸳸�����B1,B2,B3
	//��һ��
	node*back;
	int i;
	int length=line1.length();
    opr1.create_linkedList2(length);
	back=opr1.head->prev;
	for(i=length-1;i>=0;i--)
	{
		back->data=line1[i]-'0';
		back=back->prev;
	}
    //�ڶ���
	length=line2.length();
	opr2.create_linkedList2(length);
	back=opr2.head->prev;
	for( i=length-1;i>=0;i--)
	{
		back->data=line2[i]-'0';
		back=back->prev;
	}
	//������
	length=line3.length();
    opr3.create_linkedList2(length);
	back=opr3.head->prev;
	for(i=length-1;i>=0;i--)
	{
		back->data=line3[i]-'0';
		back=back->prev;
	}
}



//���������������ļ�ad5��
void bigNum::fout_put(string & s1)
{
	//�������ʽ�����������������ļ�β
	ofstream out("f:\\ad5.txt",ios::out | ios::app);
    out.write("\n",1); //����ԭ�������ݻ���������ļ���
	if(!out)
	{
		cout<<"open add.txt error!"<<endl;
	}
	else   out<<s1;
}



//���ļ�ad5����ȫ�����뵽��ʾ��
void bigNum::fdisplay()
{
	ifstream in("f:\\ad5.txt");   
    string line;  
    if(in) // �и��ļ�  
    {  
        while (getline (in, line)) 
		{
            cout<<line<<endl;  
        }  
    }  
    else // û�и��ļ�  
    {  
        cout<<"no such file"<<endl;  
    }  
	in.close();//�ر��ļ�
}



//�������ļӷ�
//����������ô��ݶ���ֵ���ݻ��������ò���ڿ������캯��������
linkedList bigNum::add_bigNum(linkedList &opr1,linkedList &opr2)//��������,(�ļ�)
{
	int i=cmplinklen(opr1,opr2);//�Ƚ�opr1��opr2�ĳ���
    if(i==1)//����opr1>=opr2
	{
		int l1=opr1.size();
		int l2=opr2.size();
		int quotient=0;
		node*ptr1=opr1.head->prev;//ptr1ָ���β�ڵ�
		node*ptr2=opr2.head->prev;//ptr2ָ���β�ڵ�
	    linkedList A1;
		A1.create_linkedList2(l1);//��������Ϊopr1,opr2�г��Ƚϴ��ߵĳ���
		node*ptr3=A1.head->prev;//ptr3ָ���β�ڵ�
		for(int j=0;j<l2;j++)//����С�ĳ��ȴ�ѭ��
		{
			int sum,remainder;
			sum=ptr1->data+ptr2->data+quotient;//sum��¼ÿλ�ĺ�
		    remainder=sum%10;//remainderΪÿλ�Ľ��
		    quotient=sum/10;//quotient��¼��λ
			ptr1=ptr1->prev;
			ptr2=ptr2->prev;
			ptr3->data=remainder;//����������������
			ptr3=ptr3->prev;

		}
		for(int k=l2;k<l1;k++)//�����ȴ�ѭ��
		{
			int sum,remainder;
			sum=ptr1->data+quotient;//���ڽ���ʣopr1�Ķ���λ
			remainder=sum%10;//remainderΪÿλ�Ľ��
			quotient=sum/10;//quotient��¼��λ
			ptr1=ptr1->prev;
			ptr3->data=remainder;//����������������
			ptr3=ptr3->prev;
		}
		if(quotient==1)//���Ľ�λ
		{
			A1.insert(1, 0);//��posλ�ú����ڵ�
		}
       
         return A1;
	}
	
	else//����opr1<opr2
	{
		int l1=opr1.size();
		int l2=opr2.size();
		int quotient=0;
		node*ptr1=opr1.head->prev;
		node*ptr2=opr2.head->prev;
		linkedList A1;
		A1.create_linkedList2(l2);//��������Ϊopr1,opr2�г��Ƚϴ��ߵĳ���
		node*ptr3=A1.head->prev;
		for(int j=0;j<l1;j++)//����С�ĳ��ȴ�ѭ��
		{
			int sum,remainder;
			sum=ptr1->data+ptr2->data+quotient;//sum��¼ÿλ�ĺ�
		    remainder=sum%10;//remainderΪÿλ�Ľ��
		    quotient=sum/10;//quotient��¼��λ
			ptr1=ptr1->prev;
			ptr2=ptr2->prev;
			ptr3->data=remainder;//����������������
			ptr3=ptr3->prev;

		}
		for(int k=l1;k<l2;k++)//�����ȴ�ѭ��
		{
			int sum,remainder;
			sum=ptr2->data+quotient;//���ڽ���ʣopr2�Ķ���λ
			remainder=sum%10;//remainderΪÿλ�Ľ��
			quotient=sum/10;//quotient��¼��λ
			ptr2=ptr2->prev;
			ptr3->data=remainder;//����������������
			ptr3=ptr3->prev;
		}
		return A1;
	}  
}



//�������ļӷ�
void bigNum::add_bigNum(linkedList &opr1,linkedList &opr2,linkedList &opr3)//��������,�����˳�������ʱ��(ȡ��)
{
	time_t t1, t2;
    time(&t1);//��ʼʱ��
	int i=cmplinklen(opr1,opr2);//�Ƚ�opr1��opr2�ĳ���
	linkedList A1;
    if(i==1)//����opr1>=opr2
	{
		int l1=opr1.size();
		int l2=opr2.size();
		int quotient=0;
		node*ptr1=opr1.head->prev;//ptr1ָ���β�ڵ�
		node*ptr2=opr2.head->prev;//ptr2ָ���β�ڵ�
		A1.create_linkedList2(l1);//��������Ϊopr1,opr2�г��Ƚϴ��ߵĳ���
		node*ptr3=A1.head->prev;
		for(int j=0;j<l2;j++)//����С�ĳ��ȴ�ѭ��
		{
			int sum,remainder;
			sum=ptr1->data+ptr2->data+quotient;//sum��¼ÿλ�ĺ�
		    remainder=sum%10;//remainderΪÿλ�Ľ��
		    quotient=sum/10;//quotient��¼��λ
			ptr1=ptr1->prev;
			ptr2=ptr2->prev;
			ptr3->data=remainder;//����������������
			ptr3=ptr3->prev;

		}
		for(int k=l2;k<l1;k++)//�����ȴ�ѭ��
		{
			int sum,remainder;
			sum=ptr1->data+quotient;//���ڽ���ʣopr1�Ķ���λ
			remainder=sum%10;//remainderΪÿλ�Ľ��
			quotient=sum/10;//quotient��¼��λ
			ptr1=ptr1->prev;
			ptr3->data=remainder;//����������������
			ptr3=ptr3->prev;
		}
		if(quotient==1)//���Ľ�λ
		{
			A1.insert(1, 0);//��posλ�ú����ڵ�
		}  
	}
	else//����opr1<opr2
	{
		int l1=opr1.size();
		int l2=opr2.size();
		int quotient=0;
		node*ptr1=opr1.head->prev;//ptr1ָ���β�ڵ�
		node*ptr2=opr2.head->prev;//ptr2ָ���β�ڵ�
		A1.create_linkedList2(l2);//��������Ϊopr1,opr2�г��Ƚϴ��ߵĳ���
		node*ptr3=A1.head->prev;
		for(int j=0;j<l1;j++)//����С�ĳ��ȴ�ѭ��
		{
			int sum,remainder;
			sum=ptr1->data+ptr2->data+quotient;//sum��¼ÿλ�ĺ�
		    remainder=sum%10;//remainderΪÿλ�Ľ��
		    quotient=sum/10;//quotient��¼��λ
			ptr1=ptr1->prev;
			ptr2=ptr2->prev;
			ptr3->data=remainder;//����������������
			ptr3=ptr3->prev;

		}
		for(int k=l1;k<l2;k++)//�����ȴ�ѭ��
		{
			int sum,remainder;
			sum=ptr2->data+quotient;//���ڽ���ʣopr2�Ķ���λ
			remainder=sum%10;//remainderΪÿλ�Ľ��
			quotient=sum/10;//quotient��¼��λ
			ptr2=ptr2->prev;
			ptr3->data=remainder;//����������������
			ptr3=ptr3->prev;
		}
	}  

    A1=mod_bigNum(A1,opr3);//A1��opr3ȡ��
	cout<<A1<<endl;
	time(&t2);//��ֹʱ��
	cout <<"����ʱ��Ϊ:"<<t2-t1<< endl;

}



//�������ļ���
void  bigNum::sub_bigNum(linkedList &opr1,linkedList &opr2)//��������,(�ļ�)
{
	int l1=opr1.size();
	int l2=opr2.size();
	if(l1>l2)//����opr1>opr2
	{
		node*ptr1=opr1.head->prev;//ptr1ָ���β�ڵ�
		node*ptr2=opr2.head->prev;//ptr2ָ���β�ڵ�
		linkedList A1;
		A1.create_linkedList2(l1);//��������Ϊopr1,opr2�г��Ƚϴ��ߵĳ���
		node*ptr3=A1.head->prev;
		int sum,sub=0;
		for(int i=0;i<l2;i++)//����С�ĳ��ȴ�ѭ��
		{    
			if((ptr1->data-sub)<ptr2->data)//��λ��opr1<opr2
			{
				sum=ptr1->data+10-ptr2->data-sub;//��ǰһλ��1,sum��¼ÿλ����Ĳ�
				sub=1;//sub��¼��λ
			}
			else//opr2>opr1
			{
				sum=ptr1->data-ptr2->data-sub;//ֱ�����
				sub=0;//sub��¼��λ
			
			}
			ptr1=ptr1->prev;
			ptr2=ptr2->prev;
			ptr3->data=sum;
			ptr3=ptr3->prev;
		}
        for(int k=l2;k<l1;k++)//�����ȴ�ѭ��
		{
			if(ptr1->data<sub)//����λΪ0
			{
			  sum=ptr1->data-sub+10;//��ǰһλ��1,sum��¼ÿλ����Ĳ�
		      sub=1;//sub��¼��λ
			}
		    else//����λ��ΪΪ0
			{
			 sum=ptr1->data-sub;
			 sub=0;//sub��¼��λ
			}
		    ptr1=ptr1->prev;
		    ptr3->data=sum;
		    ptr3=ptr3->prev;
		
		}
		if(sum==0)//�������λΪ0
		{
			A1.erase(1);//��0ɾ��
		}
		cout<<A1<<endl;
	}
	if(l1<l2)//����opr1<opr2
	{
		node*ptr1=opr1.head->prev;//ptr1ָ���β�ڵ�
		node*ptr2=opr2.head->prev;//ptr2ָ���β�ڵ�
		linkedList A1;
		A1.create_linkedList2(l2);//��������Ϊopr1,opr2�г��Ƚϴ��ߵĳ���
		node*ptr3=A1.head->prev;
		int sum,sub=0;
		for(int i=0;i<l1;i++)//����С�ĳ��ȴ�ѭ��
		{    
			if((ptr2->data-sub)<ptr1->data)
			{
				sum=ptr2->data+10-ptr1->data-sub;//��ǰһλ��1,sum��¼ÿλ����Ĳ�
				sub=1;//sub��¼��λ
			}
			else
			{
				sum=ptr2->data-ptr1->data-sub;//ֱ�����
				sub=0;//sub��¼��λ
			
			}
			ptr1=ptr1->prev;
			ptr2=ptr2->prev;
			ptr3->data=sum;//�������������
			ptr3=ptr3->prev;
		}
        for(int k=l1;k<l2;k++)//�����ȴ�ѭ��
		{
			if(ptr2->data<sub)//����λΪ0
			{
			  sum=ptr2->data-sub+10;//��ǰһλ��1,sum��¼ÿλ����Ĳ�
		      sub=1;//sub��¼��λ
			}
		    else//����λ��ΪΪ0
			{
			 sum=ptr2->data-sub;
			 sub=0;//sub��¼��λ
			}
		    ptr2=ptr2->prev;
		    ptr3->data=sum;//�������������
		    ptr3=ptr3->prev;
		
		}
		if(sum==0)//�������λΪ0
		{
			A1.erase(1);//��0ɾ��
		}
		cout<<"-"<<A1<<endl;}
	if(l1==l2)//l1��l2�������
	{   
		int m=0;
		node*ptr1=opr1.head->prev;
		node*ptr2=opr2.head->prev;
		node*optr1=opr1.head->next;
		node*optr2=opr2.head->next;
		for(int i=0;i<l1;i++)//ѭ�����ڱȽ�������������С
		{
			//m=1ʱ,��һ����������
			if(optr1->data>optr2->data)
			{
				m=1;break;
			}
			//m=2ʱ,�ڶ�����������
			else if(optr1->data<optr2->data)
			{
				m=2;break;
			}
			optr1=optr1->next;
			optr2=optr2->next;

		}
		if(m==0)//�������������
		{
			cout<<m<<endl;
		}
		if(m==1)//��һ����������
		{
			linkedList A1;
		    A1.create_linkedList2(l1);//��������Ϊ����֮�����ⳤ��
		    node*ptr3=A1.head->prev;
		    int sum,sub=0;
		    for(int i=0;i<l1;i++)//ѭ��λ����
			{
				if((ptr1->data-sub)<ptr2->data)
				{
					sum=ptr1->data+10-ptr2->data-sub;//��ǰһλ��1,sum��¼ÿλ����Ĳ�
				    sub=1;//sub��¼��λ
				}
			    else
				{
					sum=ptr1->data-ptr2->data-sub;//ֱ�����
				    sub=0;//sub��¼��λ
				}
			    ptr1=ptr1->prev;
		 	    ptr2=ptr2->prev;
			    ptr3->data=sum;//�������������
			    ptr3=ptr3->prev;
			}
		    if(sum==0)//�������λΪ0
			{
			    A1.erase(1);//��0ɾ��
			}
		    node*ptr4=A1.head->next;
		    node*ptr5=ptr4->next;
		    node*ptr6=A1.head;
		    while(ptr4->data==0)//����0001���,ѭ������ɾ������0
			{
			    delete ptr4;//ɾ��
			    ptr4=ptr5;
		 	    ptr5=ptr5->next;
			    A1.lsize=A1.lsize-1;//�����ȼ�1
			}
		    ptr6->next=ptr4;//ɾ���ڵ�֮������Ӳ���
		    ptr4->prev=ptr6;
		    cout<<A1<<endl;
		}
		else if(m==2)//�ڶ�����������
		{
			linkedList A1;
		    A1.create_linkedList2(l1);//��������Ϊ����֮�����ⳤ��
		    node*ptr3=A1.head->prev;
		    int sum,sub=0;
		    for(int i=0;i<l1;i++)//ѭ��λ����
			{
				if((ptr2->data-sub)<ptr1->data)
				{
					sum=ptr2->data+10-ptr1->data-sub;//��ǰһλ��1,sum��¼ÿλ����Ĳ�
				    sub=1;//sub��¼��λ
				}
			    else
				{
					sum=ptr2->data-ptr1->data-sub;//ֱ�����
				    sub=0;//sub��¼��λ
				}
			    ptr1=ptr1->prev;
			    ptr2=ptr2->prev;
			    ptr3->data=sum;//�������������
			    ptr3=ptr3->prev;
			}
		    if(sum==0)//�������λΪ0
			{
			    A1.erase(1);//��0ɾ��
			}
            node*ptr4=A1.head->next;
		    node*ptr5=ptr4->next;
		    node*ptr6=A1.head;
		    while(ptr4->data==0)//����0001���,ѭ������ɾ������0
			{
		 	    delete ptr4;//ɾ������0
			    ptr4=ptr5;
			    ptr5=ptr5->next;
			    A1.lsize=A1.lsize-1;//�����ȼ�1
			}
		    ptr6->next=ptr4;//ɾ���ڵ�֮������Ӳ���
		    ptr4->prev=ptr6;
		    cout<<"-"<<A1<<endl;
		}
	}	
}



//����������
void  bigNum::sub_bigNum(linkedList &opr1,linkedList &opr2,linkedList &opr3)//��������,�����˳�������ʱ��(ȡ��)
{
	time_t t1, t2;//��¼��������ʱ��
    time(&t1);//��ʼʱ��
	int l1=opr1.size();
	int l2=opr2.size();
	if(l1>l2)//��һ�����������ȴ��ڵڶ���������
	{
		node*ptr1=opr1.head->prev;//ptr1ָ��β�ڵ�
		node*ptr2=opr2.head->prev;//ptr2ָ��β�ڵ�
		linkedList A1;
		A1.create_linkedList2(l1);//��������Ϊopr1,opr2�г��Ƚϴ��ߵĳ���
		node*ptr3=A1.head->prev;
		int sum,sub=0;
		for(int i=0;i<l2;i++)//����С�ĳ��ȴ�ѭ��
		{    
			if((ptr1->data-sub)<ptr2->data)
			{
				sum=ptr1->data+10-ptr2->data-sub;//��ǰһλ��1,sum��¼ÿλ����Ĳ�
				sub=1;//sub��¼��λ
			}
			else
			{
				sum=ptr1->data-ptr2->data-sub;//ֱ�Ӽ�
				sub=0;//sub��¼��λ
			}
			ptr1=ptr1->prev;
			ptr2=ptr2->prev;
			ptr3->data=sum;//�������������
			ptr3=ptr3->prev;
		}
        for(int k=l2;k<l1;k++)//�����ȴ�ѭ��
		{
			if(ptr1->data<sub)//����λΪ0
			{
				sum=ptr1->data-sub+10;//��ǰһλ��1
		        sub=1;//��¼��λ
			}
		    else
			{
				sum=ptr1->data-sub;//����λ��Ϊ0
			    sub=0;//��¼��λ
			}
		    ptr1=ptr1->prev;
		    ptr3->data=sum;//�������������
		    ptr3=ptr3->prev;
		
		}
		if(sum==0)//�������λΪ0
		{
			A1.erase(1);//ɾ��0
		}
		A1=mod_bigNum(A1,opr3);//ȡ�����
		cout<<A1<<endl;
	}
	if(l1<l2)//��һ������������С�ڵڶ���������
	{
		cout<<"No Exit(Regardless of the negative)"<<endl;
	}
	if(l1==l2)//��һ�����������ȵ��ڵڶ���������
	{   int m=0;
		node*ptr1=opr1.head->prev;
		node*ptr2=opr2.head->prev;
		node*optr1=opr1.head->next;
		node*optr2=opr2.head->next;
		for(int i=0;i<l1;i++)//ѭ���Ƚ������������Ĵ�С
		{
			//m=1 opr1>opr2,m=2 opr1<opr2
			if(optr1->data>optr2->data)
			{
				m=1;break;
			}
			else if(optr1->data<optr2->data)
			{
				m=2;break;
			}
			optr1=optr1->next;
			optr2=optr2->next;
		}
		if(m==0)//opr1=opr2
		{
			cout<<m<<endl;//0���κ���ȡ���Ϊ0
		}
		if(m==1)//opr1>opr2
		{
			linkedList A1;
		    A1.create_linkedList2(l1);//��������Ϊ����֮�����ⳤ��
		    node*ptr3=A1.head->prev;
		    int sum,sub=0;
		    for(int i=0;i<l1;i++)//ѭ��λ����
			{
				if((ptr1->data-sub)<ptr2->data)
				{
					sum=ptr1->data+10-ptr2->data-sub;//��ǰһλ��1,sum��¼ÿλ����Ĳ�
				    sub=1;//��¼��λ
				}
			    else
				{
					sum=ptr1->data-ptr2->data-sub;//ֱ�����
				    sub=0;//��¼��λ
				}
			    ptr1=ptr1->prev;
			    ptr2=ptr2->prev;
			    ptr3->data=sum;//���������������
			    ptr3=ptr3->prev;
			}
		    if(sum==0)//�������λΪ0
			{
				A1.erase(1);//ɾ��0
			}
		    node*ptr4=A1.head->next;
		    node*ptr5=ptr4->next;
		    node*ptr6=A1.head;
		    while(ptr4->data==0)//����0001��ѭ��ʵ��ɾ��
			{
				delete ptr4;//�ͷſռ�
			    ptr4=ptr5;
			    ptr5=ptr5->next;
			    A1.lsize=A1.lsize-1;//���ȼ�1
			}
		    ptr6->next=ptr4;
	     	ptr4->prev=ptr6;
		    A1=mod_bigNum(A1,opr3);//ȡ�����
		    cout<<A1<<endl;
		}
		else if(m==2)//opr1<opr2
		{
			cout<<"No Exit(Regardless of the negative)<<endl";
		}
	}
    time(&t2);//��ֹʱ��
    cout<<"����ʱ��:"<<t2-t1<<endl;	
}



//�������˷�
linkedList bigNum::mul_bigNum(linkedList &opr1,linkedList &opr2)//�����β�
{
	//ptr3�����ÿ����˵Ľ����������,ptr4����0000��ͼ��ʾ��ǰ��λ
	//                                        0000
 	node*ptr1,*ptr2,*ptr3,*ptr4,*optr1,*optr2;//optr1,optr2���ڴӺ���ǰʵ����˲���
	int l1=opr1.size();
    int l2=opr2.size();
	ptr1=opr1.head->next;//ptr1��ptr2�����ж����������Ƿ�Ϊ0����
	ptr2=opr2.head->next;
    optr2=opr2.head->prev;
	if(ptr1->data==0||ptr2->data==0)//����������һ��Ϊ0
	{
		linkedList A1;
		A1.insert(0,0);//0����
        return A1;
	}
	else
	{
		linkedList A1;
		A1.create_linkedList1(l1+l2);//��������Ϊ����֮��,��ȫ����ʼ��Ϊ0
	    ptr4=A1.head->prev;
	    ptr3=ptr4;
	    for(int j=0;j<l2;j++)//����˫��ѭ��
		{
			if(optr2->data==0)
			{
				optr2=optr2->prev;
                ptr4=ptr4->prev;
	            ptr3=ptr4;
			    continue;//��������ѭ��
			}
		    int temp=0;
		    optr1=opr1.head->prev;
		    for(int i=0;i<l1;i++)//����һ��������λ����ѭ��
			{ 
				//ÿ��Ҫ�������������:
				temp=temp+(optr2->data)*(optr1->data)+ptr3->data;
			    ptr3->data=temp%10;//���
			    temp=temp/10;//��λ
			    optr1=optr1->prev;
		        ptr3=ptr3->prev;

			}
		    ptr3->data=ptr3->data+temp;//��λ��Ľ����������
		    optr2=optr2->prev;
		    ptr4=ptr4->prev;
	        ptr3=ptr4;
		}
	    if(A1.head->next->data==0)//�����λΪ0
			A1.erase(1);//ɾ��0
	    return A1;
	}
}



//�������˷�
void bigNum::mul_bigNum(linkedList &opr1,linkedList &opr2,linkedList &opr3)//��������,�����˳�������ʱ��(ȡ��)
{
	time_t t1, t2;//��¼��������ʱ��
    time(&t1);//��¼��ʼʱ��
	//ptr3�����ÿ����˵Ľ����������,ptr4����0000��ͼ��ʾ��ǰ��λ
	//                                        0000
	linkedList A1;
	node*ptr1,*ptr2,*ptr3,*ptr4,*optr1,*optr2;//optr1,optr2���ڴӺ���ǰʵ����˲���
	int l1=opr1.size();
    int l2=opr2.size();
	ptr1=opr1.head->next;//ptr1��ptr2�����ж����������Ƿ�Ϊ0����
	ptr2=opr2.head->next;
    optr2=opr2.head->prev;
	if(ptr1->data==0||ptr2->data==0)//����������һ��Ϊ0
	{
		A1.insert(0,0);//0����
	}
	else
	{
		A1.create_linkedList1(l1+l2);//��������Ϊ����֮��,��ȫ����ʼ��Ϊ0
	    ptr4=A1.head->prev;
	    ptr3=ptr4;
	    for(int j=0;j<l2;j++)//����˫��ѭ��
		{
			if(optr2->data==0)
			{
				optr2=optr2->prev;
                ptr4=ptr4->prev;
	            ptr3=ptr4;
			    continue;//��������ѭ��
			}
		    int temp=0;
		    optr1=opr1.head->prev;
		    for(int i=0;i<l1;i++)//����һ��������λ����ѭ��
			{  
				temp=temp+(optr2->data)*(optr1->data)+ptr3->data;
			    ptr3->data=temp%10;//���
			    temp=temp/10;//��λ
			    optr1=optr1->prev;
		        ptr3=ptr3->prev;

			}
		    ptr3->data=ptr3->data+temp;//��λ��Ľ����������
		    optr2=optr2->prev;
		    ptr4=ptr4->prev;
	        ptr3=ptr4;
		}
	    if(A1.head->next->data==0)//�����λΪ0
		    A1.erase(1);//ɾ��0
	}
	 A1=mod_bigNum(A1,opr3);//ȡ�����
	 cout<<A1;
	 time(&t2);//��ֹʱ��
     cout<<"                                       *���������ʱ��Ϊ:"<<t2-t1<<"s"<< endl;	
}



//�����Ӻ���--����,�˼������������ڴ�����С��
linkedList bigNum::div_subbigNum(linkedList &opr1,linkedList &opr2)
{
	int l1=opr1.size();
	int l2=opr2.size();
	node*ptr1=opr1.head->prev;//ָ������β
	node*ptr2=opr2.head->prev;//ָ������β
	linkedList d;
	d.create_linkedList2(l1);//�ϳ��ߵĳ���
	node*ptr3=d.head->prev;
	int sum,sub=0;
	for(int i=0;i<l2;i++)
	{    
		if((ptr1->data-sub)<ptr2->data)
		{
			sum=ptr1->data+10-ptr2->data-sub;//��λ�����
			sub=1;//��¼��λ
		}
		else
		{
			sum=ptr1->data-ptr2->data-sub;//ֱ�����
			sub=0;//��¼��λ
		}
		ptr1=ptr1->prev;
		ptr2=ptr2->prev;
		ptr3->data=sum;//���������������
		ptr3=ptr3->prev;
	}
    for(int k=l2;k<l1;k++)//��λ��ѭ��
	{   
		if(ptr1->data<sub)//С��0
		{
			sum=ptr1->data-sub+10;//��λ���
		    sub=1;//��¼��λ
		}
		else
		{
			sum=ptr1->data-sub;//ֱ�����
			sub=0;//��λ
		}
		    ptr1=ptr1->prev;
		    ptr3->data=sum;//���������������
		    ptr3=ptr3->prev;
	}
	node*ptr4=d.head->next;
    node*ptr5=ptr4->next;
    node*ptr6=d.head;
	while(ptr4->data==0&&d.size()>1)//����0001���,ѭ������ɾ������0
	{
		 	    delete ptr4;//ɾ������0
			    ptr4=ptr5;
			    ptr5=ptr5->next;
			    d.lsize=d.lsize-1;//�����ȼ�1
	}
	ptr6->next=ptr4;//ɾ���ڵ�֮������Ӳ���
    ptr4->prev=ptr6;
	return d;
}



//����������
linkedList bigNum::div_bigNum(linkedList &opr1,linkedList &opr2)//��������
{	
	if(compare(opr1,opr2)==-1)//�����ȱ�����������
	{
		linkedList s;
		s.insert(0,0);
		return s;
	}
	else//�����ͱ�������Ȼ򱻳����ȳ��������� 
	{
		if(opr2.head->next->data==0)//����Ϊ0�����
		{
			cout<<"No Exit"<<endl;
		    linkedList s;//������ͷ�ڵ������
		    return  s;
		}
	    else if(opr1.head->next->data==0)//������Ϊ0�����
		{
		    linkedList s;
		    s.insert(0,0);//0����
		    return s;
		}
        else//�������
		{
		    linkedList c;
	        int m;
	        node*ptr;
	        int l1=opr1.size();
	        int l2=opr2.size();
	        linkedList s;//��
	        int clength=l2-1;
            if(clength!=0)
			{
				c.create_linkedList2(clength);
	            node*ptr1=c.head->next;
	            node*ptr2=opr1.head->next;
	            for(int i=0;i<l2-1;i++)//ѭ����ֵ
				{
					ptr1->data=ptr2->data;
		            ptr1=ptr1->next;
		            ptr2=ptr2->next;
				}
			}	
	        node*i1=opr1.head->next;
	        for(int k=0;k<l2-1;k++)//��i1��¼i
		        i1=i1->next;
	        for(int i=l2-1;i<l1;i++)
			{
		       int cnt=0;//cnt��¼�������
		       ptr=c.head->next;
		       if(ptr->data==0)//���֮���Ϊ0,��0���������0
			   {
			      node*change=c.head->next;
			      change->data=i1->data;
			   }
		       else//����������һλ��
			   {
			      c.insert(i1->data,c.size());

			   }
		       while( (m=compare(c,opr2))!=-1)//�Ƚ��������Ĵ�С
			   {
			      c=div_subbigNum(c,opr2);//������
			      cnt++;//��¼��������
			
			   }
		       i1=i1->next;
		       s.insert(cnt,s.size());//��ÿ�������Ĵ������뵽s��
		   }
	       if(s.head->next->data==0)//�������Ϊ0
			   s.erase(1);//ɾ��0
           return s;
	   }
	}
}



//�������ĳ���
void bigNum::div_bigNum(linkedList &opr1,linkedList &opr2,linkedList &opr3)//��������,�����˳�������ʱ��(ȡ��)
{
	time_t t1, t2;//��¼��������ʱ��
    time(&t1);//��¼��ʼʱ��
	if(compare(opr1,opr2)==-1)//�����ȱ�����������
	{
		linkedList s;
		s.insert(0,0);
		cout<<s;
	}
	else//�����ͱ�������Ȼ򱻳����ȳ���������
	{	
		if(opr2.head->next->data==0)//����Ϊ0
		{
		    cout<<"No Exit"<<endl;
		}
	    else if(opr1.head->next->data==0)//������Ϊ0
		{
		    linkedList s;
		    s.insert(0,0);//0����
		    cout<<s;
		}
	    else//�������
		{
			linkedList c,s;
	        int m;
	        node*ptr;
	        int l1=opr1.size();
	        int l2=opr2.size();
	        int clength=l2-1;
            if(clength!=0)
			{
				c.create_linkedList2(clength);
	            node*ptr1=c.head->next;
	            node*ptr2=opr1.head->next;
	            for(int i=0;i<l2-1;i++)//ѭ����ֵ
				{
					ptr1->data=ptr2->data;
		            ptr1=ptr1->next;
		            ptr2=ptr2->next;
				}
			}	
	        node*i1=opr1.head->next;
	        for(int k=0;k<l2-1;k++)//��i1��¼i
		        i1=i1->next;
	        for(int i=l2-1;i<l1;i++)
			{
				int cnt=0;//cnt��¼�������
		        ptr=c.head->next;
		        if(ptr->data==0)//���֮���Ϊ0,��0���������0
				{
					node*change=c.head->next;
			        change->data=i1->data;
				}
		        else
				{
					c.insert(i1->data,c.size());//����������һλ��

				}
		        while( (m=compare(c,opr2))!=-1)//�Ƚ��������Ĵ�С
				{
					c=div_subbigNum(c,opr2);//����
			        cnt++;//��¼��������
				}
		        i1=i1->next;
		        s.insert(cnt,s.size());//��ÿ�������Ĵ������뵽s��
			}
	
	        if(s.head->next->data==0)//�������Ϊ0
				s.erase(1);//ɾ��0
	        s=mod_bigNum(s,opr3);//ȡ��
            cout<<s;
		}	
	}
	time(&t2);//��ֹʱ��
    cout<<"                                       *���������ʱ��Ϊ:"<<t2-t1<<"s"<< endl;
}



//������ȡģ
linkedList bigNum::mod_bigNum(linkedList &opr1,linkedList &opr2)
{
	linkedList c;
	if(compare(opr1,opr2)==-1)//ģ���ȱ�ģ��������
	{
		c=opr1;
	}
	else{
		if(opr2.head->next->data==0)//ģ��Ϊ������
		{
		   cout<<"Modulus is not zero";
		}
	    int m;
	    node*ptr;
	    int l1=opr1.size();
	    int l2=opr2.size();
	    linkedList s;
	    int clength=l2-1;
        if(clength!=0)
		{
		    c.create_linkedList2(clength);
	        node*ptr1=c.head->next;
	        node*ptr2=opr1.head->next;
	        for(int i=0;i<l2-1;i++)
			{
			    ptr1->data=ptr2->data;
		        ptr1=ptr1->next;
		        ptr2=ptr2->next;
			}
		}	
	    node*i1=opr1.head->next;
	    for(int k=0;k<l2-1;k++)//��i1��¼i
		   i1=i1->next;
	    for(int i=l2-1;i<l1;i++)
		{
		   int cnt=0;
		   ptr=c.head->next;
		   if(ptr->data==0)
		   {
			  node*change=c.head->next;
			  change->data=i1->data;
		   }
		   else
		   {
			  c.insert(i1->data,c.size());

		   }
		   while( (m=compare(c,opr2))!=-1)
		   {
			  c=div_subbigNum(c,opr2);//����
			  cnt++;
			
		   }
		   i1=i1->next;
		}
	}
	return c;//����
}



//����ָ������ĳ˷��Ӻ���
linkedList bigNum::ind_mulbigNum(linkedList &opr1,linkedList &opr2)
{   
    //ptr3�����ÿ����˵Ľ����������,ptr4����0000��ͼ��ʾ��ǰ��λ
	//                                        0000
	linkedList A1;
	node*ptr1,*ptr2,*ptr3,*ptr4,*optr1,*optr2;//optr1,optr2���ڴӺ���ǰʵ����˲���
	int l1=opr1.size();
    int l2=opr2.size();
	ptr1=opr1.head->next;
	ptr2=opr2.head->next;
    optr2=opr2.head->prev;
	if(ptr1->data==0||ptr2->data==0)//������һ������Ϊ0
	{
		A1.insert(0,0);//0����
	}
	else
	{
		A1.create_linkedList1(l1+l2);//����Ϊ��������֮��
	    ptr4=A1.head->prev;
	    ptr3=ptr4;
	    for(int j=0;j<l2;j++)
		{
			if(optr2->data==0)
			{
				optr2=optr2->prev;
                ptr4=ptr4->prev;
	            ptr3=ptr4;
			    continue;//��������ѭ��
			}
		    int temp=0;
		    optr1=opr1.head->prev;
		    for(int i=0;i<l1;i++)
			{  
				temp=temp+(optr2->data)*(optr1->data)+ptr3->data;
			    ptr3->data=temp%10;//���
			    temp=temp/10;//��λ
			    optr1=optr1->prev;
		        ptr3=ptr3->prev;

			}
		    ptr3->data=ptr3->data+temp;//��λ��Ľ����������
		    optr2=optr2->prev;
		    ptr4=ptr4->prev;
	        ptr3=ptr4;
		}
	    if(A1.head->next->data==0)//�����λΪ0
		    A1.erase(1);//ɾ��0
	}
	 return A1;
}



//������ָ������
linkedList bigNum::ind_bigNum(linkedList opr1,linkedList opr2)
{
	linkedList c;
    if(opr2.size()==1&&opr2.head->next->data==0)//ָ����0�����
	{
		c.insert(1,0);
	}
	else if(opr2.size()==1&&opr2.head->next->data==1)//ָ����1�����
	{
		c=opr1;
	}
	else
	{
		linkedList a;
        a.insert(1,0);
	    c=ind_mulbigNum(opr1,opr1);//��һ�γ˷�,ƽ��
	    opr2=div_subbigNum(opr2,a);//ѭ��������1
	    while(compare(opr2,a)==1)//��opr2>=1
		{
		    c=ind_mulbigNum(c,opr1);//����
		    opr2=div_subbigNum(opr2,a);//ѭ��������1
		}
	}
	return c;	
}



//������ָ������
void bigNum::ind_bigNum(linkedList opr1,linkedList opr2,linkedList &opr3)//��������,�����˳�������ʱ��(ȡ��)
{
	time_t t1, t2;//��¼��������ʱ��
    time(&t1);//��¼��ʼʱ��
	linkedList c;
	if(opr2.size()==1&&opr2.head->next->data==0)//ָ����0�����
	{
		c.insert(1,0);
	}
	else if(opr2.size()==1&&opr2.head->next->data==1)//ָ����1�����
	{
		c=opr1;
	}
	else
	{
		linkedList a;
        a.insert(1,0);
	    c=ind_mulbigNum(opr1,opr1);//����һ�γ˷�,ƽ��
	    opr2=div_subbigNum(opr2,a);//ѭ��������1
	    while(compare(opr2,a)==1)//��opr2>=1
		{
		   c=ind_mulbigNum(c,opr1);//����
		   opr2=div_subbigNum(opr2,a);//ѭ��������1
		}
	}
	c=mod_bigNum(c,opr3);//ȡ��
	cout<<c;
	time(&t2);//��ֹʱ��
	cout<<"                                       *���������ʱ��Ϊ:"<<t2-t1<<"s"<< endl;
}



//��������
linkedList::~linkedList()//�����������ͷ��ڴ�
{   
	int i;
	node*ptr=head;
	node*douptr;
	for(i=0;i<=lsize;i++)//�ͷŽڵ�ռ�
	{
		douptr=ptr;
	    ptr=ptr->next;
	    delete douptr;
    }
}

