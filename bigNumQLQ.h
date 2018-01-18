#include <iostream>
using namespace std;
class node//�ڵ���
{
   public:
      int data;     
      node *prev,*next;    
	  node():prev(NULL),next(NULL){}	  
      node(const int&item,node *prevNode=NULL,node *nextNode=NULL):
	  data(item), prev(prevNode),next(nextNode){ }

};
class linkedList//������
{       
	public:
		friend class bigNum;//��������������Ϊ���������Ԫ��
		linkedList();//Ĭ�Ϲ��캯��
		linkedList(const linkedList & obj);//�������캯��
		linkedList & operator=(const linkedList& rhs);//��ֵ����
		void create_linkedList1(int n);//����˫��ѭ��������ʼ��Ϊ0
		void create_linkedList2(int n);//����˫��ѭ������
		int size()const;//��ȡ������
		void insert(int item, int pos);//��posλ�ú����ڵ�
		void erase(int pos);//ɾ���ڵ�
		void display(ostream & out);//ֱ�������������
		~linkedList();//�����������ͷ��ڴ�
    private:
		node *head;//ͷָ��
		int lsize;//����
};
ostream & operator<<(ostream & ,linkedList & );
class bigNum
{
    public:
	    string translation(linkedList&opr);//���������ݴ洢���ַ�����
		void input_store(linkedList& opr1,linkedList &opr2);////���������ַ������͵Ĳ�����,������洢��������
		void input_store(linkedList& opr1,linkedList &opr2,linkedList &opr3);//���������ַ������͵Ĳ�����,������洢��������
		void finput_store(linkedList& opr1,linkedList &opr2);//���ļ��еĵ�n�����ݴ洢��������
		void finput_store(linkedList& opr1,linkedList &opr2,linkedList &opr3);//���ļ��еĵ�n�����ݴ洢��������
		void fout_put(string & s1);//���������ý��������ļ�����һ��
		void fdisplay();//���ļ�������ʾ����Ļ
		int  compare(linkedList& opr1,linkedList &opr2);//�Ƚ������������Ĵ�С
		int  cmplinklen(linkedList& opr1,linkedList &opr2);//�����ȱȽ�
		linkedList add_bigNum(linkedList &opr1,linkedList &opr2);//�ӷ�
		void add_bigNum(linkedList &opr1,linkedList &opr2,linkedList &opr3);
		void sub_bigNum(linkedList &opr1,linkedList &opr2);//����
		void sub_bigNum(linkedList &opr1,linkedList &opr2,linkedList &opr3);
		linkedList mul_bigNum(linkedList &opr1,linkedList &opr2);//�˷�
		void mul_bigNum(linkedList &opr1,linkedList &opr2,linkedList &opr3);
		linkedList div_subbigNum(linkedList &opr1,linkedList &opr2);//�����Ӻ���
		linkedList ind_mulbigNum(linkedList &opr1,linkedList &opr2);//ָ���Ӻ���
		linkedList mod_bigNum(linkedList &opr1,linkedList &opr2);//ȡģ
	    linkedList div_bigNum(linkedList &opr1,linkedList &opr2);//����
		void div_bigNum(linkedList &opr1,linkedList &opr2,linkedList &opr3);
	    linkedList ind_bigNum(linkedList opr1,linkedList opr2);//ָ��
		void ind_bigNum(linkedList opr1,linkedList opr2,linkedList &opr3);
};
 
