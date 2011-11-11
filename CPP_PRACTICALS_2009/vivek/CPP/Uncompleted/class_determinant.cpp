class matrix
{
    public:
        void setData(int& );
        void printMatrix();
        double determinant(int);
    private:
        int size;
        double* a;
};        

void matrix::setData(int& size)
{
    a = new double[size];
    cout<<"Enter the values of square matrix ,"<<size<<" values each row: "<<endl;
    for(int i=0;i<size;i++)
    {
        cout<<" Row "<<i<<" : ";
        for(int j=0;j<size;j++)
        {
            cin>>a[i][j];
        }
        cout<<endl;       
    } 
    return;
}    

void matrix::printMatrix()
{
    cout<<" The matrix you entered is: "<<endl;
    for(int i=0;i<size;i++)
    {
        cout<<setw(6);
        for(int j=0;j<size;j++)
        {
            cout<<a[i][j]<<setw(3);
        }
        cout<<endl;    
    }    
    return;
}    

double matrix::determinant(size)
{
  return 2.0;  
}       
