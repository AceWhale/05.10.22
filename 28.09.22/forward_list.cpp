#include <iostream>
using namespace std;

template<class T>
struct Element
{
    // Данные
    T data;
    // Адрес следующего элемента списка
    Element<T>* Next;
};

// Односвязный список
template<class T>
class List
{
    // Адрес головного элемента списка
    Element<T>* Head;
    // Адрес головного элемента списка
    Element<T>* Tail;
    // Количество элементов списка
    int Count;

public:
    // Конструктор
    List();
    // Деструктор
    ~List();

    // Добавление элемента в список
    // (Новый элемент становится последним)
    void Add(T data);

    // Удаление элемента списка
    // (Удаляется головной элемент)
    void Del();
    // Удаление всего списка
    void DelAll();

    // Распечатка содержимого списка
    // (Распечатка начинается с головного элемента)
    void Print();

    // Получение количества элементов, находящихся в списке
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
    // Изначально список пуст
    Head = Tail = NULL;
    Count = 0;
}

template<class T>
List<T>::~List()
{
    // Вызов функции удаления
    DelAll();
}

//template<class T>
//int List<T>::GetCount()
//{
//    // Возвращаем количество элементов
//    return Count;
//}

template<class T>
void List<T>::Add(T data)
{
    // создание нового элемента
    Element<T>* temp = new Element<T>;

    // заполнение данными
    temp->data = data;
    // следующий элемент отсутствует
    temp->Next = NULL;
    // новый элемент становится последним элементом списка
    // если он не первый добавленный
    if (Head != NULL) {
        Tail->Next = temp;
        Tail = temp;
    }
    // новый элемент становится единственным
    // если он первый добавленный
    else {
        Head = Tail = temp;
    }
    Count++;
}

template<class T>
void List<T>::Del()
{
    // запоминаем адрес головного элемента
    Element<T>* temp = Head;
    // перебрасываем голову на следующий элемент
    Head = Head->Next;
    // удаляем бывший головной элемент
    delete temp;
}

template<class T>
void List<T>::DelAll()
{
    // Пока еще есть элементы
    while (Head != 0)
        // Удаляем элементы по одному
        Del();
}

template<class T>
void List<T>::Print()
{
    //// запоминаем адрес головного элемента
    //Element<T>* temp = Head;
    //// Пока еще есть элементы
    //while (temp != 0)
    //{
    //    // Выводим данные
    //    cout << temp->data << " ";
    //    // Переходим на следующий элемент
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
// Тестовый пример
void main()
{
    // Создаем объект класса List
    //List<char> lst;

    //// Тестовая строка
    //char s[] = "Hello, World !!!\n";
    //// Выводим строку
    //cout << s << "\n\n";
    //// Определяем длину строки
    //int len = strlen(s);
    //// Загоняем строку в список
    //for (int i = 0; i < len; i++)
    //    lst.Add(s[i]);
    //// Распечатываем содержимое списка
    //lst.Print();
    //// Удаляем три элемента списка
    //lst.Del();
    //lst.Del();
    //lst.Del();
    ////Распечатываем содержимое списка
    //lst.Print();

    List<int> int_list;
    int_list.Add(10);
    int_list.Add(20);
    int_list.Add(30);
    int_list.Insert(2, 15);
    int_list.Print();
    cout << endl;
}