#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

ifstream f("date.in");
ofstream g("date.out");

template<class T>
class Vector
{
private:
	T * array;
	int nr_elem;
	int dim_max;
public:
    Vector(){array = NULL;nr_elem=0;dim_max=0;}
    Vector(int dim,T elem);
    Vector(Vector &ob);
    Vector operator=(const Vector &ob);
    void push_back(T x);
    void pop_back();
    void insert(T x,int poz);
    void remove(int poz);
    T &operator[](int i);
    int operator++()
     {  ++nr_elem;
        return nr_elem;}
    int operator++(int)
    {   int aux=nr_elem;
        nr_elem++;
        return aux;}
    operator int()const
    {
        return dim_max;
    }
    operator bool()const
    {
       if(nr_elem==0) return 0;
       return 1;
    }
    Vector *operator->() {return this;}
    Vector &operator *(){return *this;}
    bool operator==(Vector &ob)
    {

        if(nr_elem!=ob.nr_elem) return 0;
        for(int i = 0 ; i< nr_elem;i++)
        {
            if(array[i]!=ob.array[i]) return 0;
        }
        return 1;
    }

    bool operator!=(Vector &ob)
    {
        if(nr_elem!=ob.nr_elem) return 1;
        for(int i = 0 ; i< nr_elem;i++)
        {
            if(array[i]!=ob.array[i]) return 1;
        }
        return 0;
    }
    void afisare(){for(int i = 0 ; i <nr_elem;i++){g<<array[i]<<" ";}g<<endl;}
~Vector();
};
template <class T>
 Vector<T>::Vector(int dim,T elem)
{
    array=new T[dim];
    dim_max=dim;
    nr_elem=dim;
    for(int i = 0 ; i < dim ;i++)
    {
     array[i]=elem;
    }
}
template <class T>

 Vector<T>::Vector(Vector &ob)
{

    array=new T[ob.dim_max];
    dim_max=ob.dim_max;
    nr_elem=ob.nr_elem;
    for(int i = 0 ; i < nr_elem;i++)
        {
            array[i]=ob.array[i];
        }

}
template <class T>
Vector<T> Vector<T>::operator=(const Vector &ob)
{

        try{
         if(this==&ob)  throw "Exceptie";
         if(array!=NULL){delete[]array;
         array=NULL;}
         array=new T[ob.dim_max];
         dim_max=ob.dim_max;
        nr_elem=ob.nr_elem;
        for(int i = 0 ; i < nr_elem; i++)
        {
            array[i]=ob.array[i];
        }
        }
        catch (const char*exceptie)
        {
            g<<"Eroare copiere";
        }

    return *this;
}
template<class T>
void Vector<T>::push_back(T x)
{
     try
     {
        if(dim_max==nr_elem) throw "Exceptie";
        array[nr_elem]=x;
        nr_elem++;
     }

   catch(const char*error) {
       cout<<"Dublam dimensiunea\n";
        T*aux=new T[nr_elem];
        for(int i = 0 ; i <nr_elem;i++)
        {
            aux[i]=array[i];
        }
        delete[]array;
        array=NULL;
        array=new T[2*nr_elem];
         for(int i = 0 ; i <nr_elem;i++)
        {
            array[i]=aux[i];
        }
        dim_max=2*nr_elem;
        array[nr_elem]=x;
        nr_elem++;
        return;
    }

}
template<class T>
void Vector<T>::pop_back()
{

    if(nr_elem==0) {g<<"empty\n";return;}
    nr_elem--;

}
template<class T>
void Vector<T>::insert(T x,int poz)
{
   try{
   if(poz==0) throw "Exceptie";
    if(dim_max==nr_elem)
    {
        T*aux=new T[nr_elem];
        for(int i = 0 ; i <nr_elem;i++)
        {
            aux[i]=array[i];
        }
        delete[]array;
        array=new T[2*nr_elem];
         for(int i = 0 ; i <nr_elem;i++)
        {
            array[i]=aux[i];
        }
        dim_max=2*nr_elem;
    }
    nr_elem++;
    for(int i = nr_elem-1;i>=poz;i--)
        array[i]=array[i-1];

    array[poz]=x;
   }
   catch(const char* error){
   g<<"nu putem insera,in afara vectorului"<<endl;
   return;
   }

}
template <class T>
void Vector<T>::remove(int poz)
{
    try{
        if(nr_elem==0) throw "Exceptie";
        for(int i = poz; i< nr_elem ;i++)
            array[i]=array[i+1];
        nr_elem--;

       }
       catch(const char*error){
       cout<<"nu avem elemente de scos"<<endl;
       return;
       }
}
template <class T>
T &Vector<T>::operator[](int i)
{
        if(i<0 || i>=nr_elem) throw "Exceptie";
         return array[i];

}
template <class T>
Vector<T>::~Vector()
{

    delete[]array;

}
int main()
{

   Vector<char> ob1(6,'a'),ob2,ob3;
  //ob1.pop_back();
  ob1.push_back('b');
  ob2=ob1;
	//try
  ob2[5]='c';//catch(const char *error){
   ob2.afisare();
  ob2.insert('q',3);

  ob2->afisare();
   //-?ob3=ob1;
   cout<<int(ob3);
  // cout<<int(ob2);

}

