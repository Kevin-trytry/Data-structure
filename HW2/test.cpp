#include <iostream>

#define ASCII_LENGTH 127
#define INPUT_ARRAY_LENGTH 200

using namespace std;

class Set{
	public:
		// constructor
		Set();
		Set(char arr[]);
		
		void printSet(void);
		
		bool find_key(char);
		
		// operator overloading
		Set operator +(Set another);
		Set operator *(Set another);
		Set operator -(Set another);
		
		bool operator >=(const Set& another);
		void operator =(const Set& another);
		
 
	private:
		// �Hbool�}�C��ܸӦr�즳�S���b�r�ꤤ�X�{
		// bool�}�C�j�p��ASCII code����
		bool ascii_list[ASCII_LENGTH];
};

// �w�]constructor
Set::Set()
{
	for(int i = 0; i < ASCII_LENGTH; i++)
		this->ascii_list[i] = false;
}

// �P�_�r�ꤤ�ҥX�{���r���s��
// �ñN�����ӽs�������L�}�C�����]��true
Set::Set(char arr[])
{
	for(int i = 0; i < ASCII_LENGTH; i++)
		this->ascii_list[i] = false;
	
	for(int i = 0; i < INPUT_ARRAY_LENGTH; i++)
	{
		if(arr[i])
			this->ascii_list[ int(arr[i]) ] = true;
		else
			break;
	}
}

// �N���XSet���֦����r����ASCII code���ǦL�X
void Set::printSet(void)
{
	for(int i = 0; i < ASCII_LENGTH; i++)
		if(this->ascii_list[i])
			cout << char(i);
}
// �^�Ƕ��XSet�����L�S�w�r��
bool Set::find_key(char ch)
{
	return ( (this->ascii_list[ int(ch) ]) ? true : false );
}

/*-----------------------------------------operator overloading-----------------------------------------------------*/

// �p��
Set Set::operator +(Set another)
{
	/* 	�M�� ascii_list �}�C
		�N���Set�t�����r���ǤJ�s��Set�æ^�� */
	Set newSet;
	for(int i = 0; i < ASCII_LENGTH; i++)
		if(this->ascii_list[i] || another.ascii_list[i])
			newSet.ascii_list[i] = true;
			
	return newSet;
}

// �涰
Set Set::operator *(Set another)
{
	/* 	�M�� ascii_list �}�C
		�N���Set�ҧt�����r���ǤJ�s��Set�æ^�� */
	Set newSet;
	for(int i = 0; i < ASCII_LENGTH; i++)
		if(this->ascii_list[i] && another.ascii_list[i])
			newSet.ascii_list[i] = true;
			
	return newSet;
}

// �t��
Set Set::operator -(Set another)
{
	/* 	�M�������X�� ascii_list �}�C
		�N �����X�t�� �B another���X���t�� ���r���ǤJ�s��Set�æ^�� */
	Set newSet;
	for(int i = 0; i < ASCII_LENGTH; i++)
		if(this->ascii_list[i] && another.ascii_list[i] == false)
			newSet.ascii_list[i] = true;
			
	return newSet;
}

// �P�_another���X�O�_�]�t�b�춰�X��
bool Set::operator >=(const Set& another)
{
	/* 	�M��another���X�� ascii_list �}�C
		�p�G�o�{ another���X�t�� �� �����X�S�� ���r���A�^��false
		�_�h�^��true */
	Set newSet;
	for(int i = 0; i < ASCII_LENGTH; i++)
		if(another.ascii_list[i] == true && this->ascii_list[i] == false)
			return false;
	
	return true;
}

// �M�ť����X�A�ñNanother���X���ȶǤJ�����X��
void Set::operator =(const Set& another)
{
	for(int i = 0; i < ASCII_LENGTH; i++)
		this->ascii_list[i] = another.ascii_list[i];
}

/*----------------------------------------------------------------------------------------------*/

int main()
{
	// ���ո�Ʋռ�
	int n;
	cin >> n;
	cin.ignore(); // �M��cin>>���j����
	
	for(int i = 0; i < n; i++)
	{
		// �Q���ժ��r��
		char str[INPUT_ARRAY_LENGTH];
		// �Q�������S�w�r��
		char key;
		
		cin.getline(str, INPUT_ARRAY_LENGTH); 
		Set A(str);
		
		cin.getline(str, INPUT_ARRAY_LENGTH);
		Set B(str);
		
		cin >> key;
		cin.ignore(); // �M��cin>>���j����
		
		Set C = A + B;
		Set D = A * B;
		
		cout << "\nTest Case "<< i+1 << ":\n";
		cout << "A: {";		A.printSet();		cout << "}\n";
		cout << "B: {";		B.printSet();		cout << "}\n";
		cout << "A+B: {";	C.printSet();		cout << "}\n";
		cout << "A*B: {";	D.printSet();		cout << "}\n";
		cout << "A-B: {";	(A-B).printSet();	cout << "}\n";
		cout << "B-A: {";	(B-A).printSet();	cout << "}\n";
		cout << ((A >= B) ? "A contains B\n" : "A does not contain B\n");
		cout << ((B >= A) ? "B contains A\n" : "B does not contain A\n");
		cout << "\'" << key << "\'" << ((A.find_key(key)) ? "is in A\n" : "is not in A\n");
		cout << "\'" << key << "\'" << ((B.find_key(key)) ? "is in B\n\n" : "is not in B\n\n");
	}
	return 0;
}