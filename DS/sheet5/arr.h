template <typename T> class Stack1;
template <typename T>class Stack2;
template <typename T>
class arr
{
      friend class Stack1<T>;
      friend class Stack2<T>;
      public:
      arr(int s=0)
      {
             size=s;   
             ptr=new T[size];
      }
      
      private:
              T* ptr;
              int size;
      
       
};
