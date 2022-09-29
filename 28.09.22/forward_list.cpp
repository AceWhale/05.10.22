#include <iostream>
using namespace std;

template<class T>
struct Element
{
    // ������
    T data;
    // ����� ���������� �������� ������
    Element<T>* Next;
};

// ����������� ������
template<class T>
class List
{
    // ����� ��������� �������� ������
    Element<T>* Head;
    // ����� ��������� �������� ������
    Element<T>* Tail;
    // ���������� ��������� ������
    int Count;

public:
    // �����������
    List();
    // ����������
    ~List();

    // ���������� �������� � ������
    // (����� ������� ���������� ���������)
    void Add(T data);

    // �������� �������� ������
    // (��������� �������� �������)
    void Del();
    // �������� ����� ������
    void DelAll();

    // ���������� ����������� ������
    // (���������� ���������� � ��������� ��������)
    void Print();

    // ��������� ���������� ���������, ����������� � ������
    //int GetCount();

    T GetCount(int pos)
    {
        Element<T>* temp = Head;
        int i = 1;
        while (i < pos)
        {
            temp = temp->Next;
            i++;
        }
        return temp->data;
    }
    void Insert(int pos, T data);
    void DelPos(int pos);
    int Find(T data);
};

template<class T>
List<T>::List()
{
    // ���������� ������ ����
    Head = Tail = NULL;
    Count = 0;
}

template<class T>
List<T>::~List()
{
    // ����� ������� ��������
    DelAll();
}

//template<class T>
//int List<T>::GetCount()
//{
//    // ���������� ���������� ���������
//    return Count;
//}

template<class T>
void List<T>::Add(T data)
{
    // �������� ������ ��������
    Element<T>* temp = new Element<T>;

    // ���������� �������
    temp->data = data;
    // ��������� ������� �����������
    temp->Next = NULL;
    // ����� ������� ���������� ��������� ��������� ������
    // ���� �� �� ������ �����������
    if (Head != NULL) {
        Tail->Next = temp;
        Tail = temp;
    }
    // ����� ������� ���������� ������������
    // ���� �� ������ �����������
    else {
        Head = Tail = temp;
    }
    Count++;
}

template<class T>
void List<T>::Del()
{
    // ���������� ����� ��������� ��������
    Element<T>* temp = Head;
    // ������������� ������ �� ��������� �������
    Head = Head->Next;
    // ������� ������ �������� �������
    delete temp;
}

template<class T>
void List<T>::DelAll()
{
    // ���� ��� ���� ��������
    while (Head != 0)
        // ������� �������� �� ������
        Del();
}

template<class T>
void List<T>::Print()
{
    //// ���������� ����� ��������� ��������
    //Element<T>* temp = Head;
    //// ���� ��� ���� ��������
    //while (temp != 0)
    //{
    //    // ������� ������
    //    cout << temp->data << " ";
    //    // ��������� �� ��������� �������
    //    temp = temp->Next;
    //}

    //cout << "\n\n";

    for (auto temp = Head; temp != 0; temp = temp->Next)
    {
        cout << temp->data << " ";
    }
}

template<class T>
void  List<T>::Insert(int pos, T data)
{
    --pos;
    Element<T>* temp = Head;
    Element<T>* new_temp = new Element<T>;
    new_temp->Next = nullptr;
    new_temp->data = data;
    for (int i = 0; i < pos - 1; i++)
        temp = temp->Next;
    new_temp->Next = temp->Next;
    temp->Next = new_temp;

}

template<class T>
void List<T>::DelPos(int pos)
{
    --pos;
    Element<T>* temp = Head;
    for (int i = 0; i < pos-1; i++)
        temp = temp->Next;
    Element<T>* del = temp->Next;
    temp->Next = del->Next;
    delete del;
}

template<class T>
int List<T>::Find(T data)
{
    Element<T>* temp = Head;
    bool check = false;
    int pos;
    for (int i = 0; i < Count; i++)
    {
        pos = i;
        if (data == temp->data)
        {
            ++pos;
            check = true;
            return pos;
        }
        else
            temp = temp->Next;
    }
    if (!check)
        return NULL;
}
// �������� ������
void main()
{
    // ������� ������ ������ List
    //List<char> lst;

    //// �������� ������
    //char s[] = "Hello, World !!!\n";
    //// ������� ������
    //cout << s << "\n\n";
    //// ���������� ����� ������
    //int len = strlen(s);
    //// �������� ������ � ������
    //for (int i = 0; i < len; i++)
    //    lst.Add(s[i]);
    //// ������������� ���������� ������
    //lst.Print();
    //// ������� ��� �������� ������
    //lst.Del();
    //lst.Del();
    //lst.Del();
    ////������������� ���������� ������
    //lst.Print();

    List<int> int_list;
    int_list.Add(10);
    int_list.Add(20);
    int_list.Add(30);
    int_list.Insert(2, 15);
    int_list.Print();
    cout << endl;
}